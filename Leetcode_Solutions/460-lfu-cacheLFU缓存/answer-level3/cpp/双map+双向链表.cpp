双map的方法：
    - map_key：记录所有的节点，key 为 key，value 为节点的指针，加速查找；
    - map_freq_list：相同频度的节点构成一条双向链表，map_freq_list key为频度，值为双向链表；

```
// 节点
typedef struct LFUListNode {
    int key;
    int value;
    int freq;
    LFUListNode* pre;
    LFUListNode* next;
    LFUListNode(int k, int v)
        : freq(0), key(k), value(v), pre(NULL), next(NULL) {}
};
// 链表
struct LFUList {
    LFUListNode* head;
    LFUListNode* tail;
};

class LFUCache {
   public:
    LFUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (capacity <= 0 || map_key.find(key) == map_key.end()) return -1;

        LFUListNode* node = map_key[key];
        // 从原链表中移除
        removeFromList(node);
        // 更新频度并加入新的链表
        node->freq++;
        insertToNewFreqList(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        // 如果 key 存在，就更新访问次数 + 1，更新值
        if (map_key.find(key) != map_key.end()) {
            LFUListNode* node = map_key[key];
            removeFromList(node);
            node->freq++;
            node->value = value;
            insertToNewFreqList(node);
            return;
        }

        LFUListNode* node = NULL;

        // 如果满了，删除最少使用的，且链表末尾的
        if (capacity == map_key.size()) {
            node = map_freq_list.begin()->second->tail->pre;
            removeFromList(node);
            map_key.erase(node->key);
        }

        // 新创建
        if (!node) {
            node = new LFUListNode(key, value);
        } else { // 这里复用原来的节点
            node->key = key;
            node->value = value;
        }
        node->freq = 1;
        map_key[key] = node;
        insertToNewFreqList(node);
    }

    void insertToNewFreqList(LFUListNode* node) {
        // 找到新的链
        LFUList* freqList = NULL;

        // 如果 freq 对应的链为空，创建新的链
        if (map_freq_list.find(node->freq) == map_freq_list.end()) {
            freqList = newList();
            map_freq_list[node->freq] = freqList;
        } else { // 链已存在
            freqList = map_freq_list[node->freq];
        }

        // 加入新的链中
        node->next = freqList->head->next;
        node->next->pre = node;
        node->pre = freqList->head;
        freqList->head->next = node;
    }

    void removeFromList(LFUListNode* node) {
        // 从原链中移除节点
        node->next->pre = node->pre;
        node->pre->next = node->next;

        LFUList* list = map_freq_list[node->freq];
        if (list->head->next == list->tail) {
            map_freq_list.erase(node->freq);
        }
    }

    LFUList* newList() {
        LFUList* lfuList = new LFUList();
        lfuList->head = new LFUListNode(-1, -1);
        lfuList->tail = new LFUListNode(-1, -1);
        lfuList->head->next = lfuList->tail;
        lfuList->tail->pre = lfuList->head;
        return lfuList;
    }

   private:
    map<int, LFUListNode*> map_key;
    map<int, LFUList*> map_freq_list;
    int capacity = 0;
};
```
