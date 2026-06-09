参考官方题解的c++版本
```
class LRUCache {
public:
    struct DLNode {
        int key;
        int value;
        DLNode* prev;
        DLNode* next;
        DLNode() : key(0), value(0), prev(NULL), next(NULL) {};
        DLNode(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {};
    };
    map<int, DLNode*> cache;
    DLNode* head;
    DLNode* tail;
    int capacity;
    int size;
    // 撤下node
    void retake(DLNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    // 删除尾部
    void pop_tail() {
        auto node = tail->prev;
        retake(node);
        cache.erase(node->key);
        delete node;
        --size;
    }
    // 头部添加
    void add(DLNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    // 移动到头部
    void move_to_front(DLNode* node) {
        retake(node);
        add(node);
    }
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new DLNode;
        tail = new DLNode;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) return -1;
        auto node = cache[key];
        move_to_front(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key) == 0) {
            if (size == capacity) pop_tail();
            auto node = new DLNode(key, value);
            cache[key] = node;
            add(node);
            ++size;
        } else {
            auto node = cache[key];
            node->value = value;
        }
        move_to_front(cache[key]);
    }
};
```

![image.png](https://pic.leetcode-cn.com/cba7af688defb17eb64d7cab855c963e46d03da58ceeb73dd5bacb09f795a5d4-image.png)
