使用 map 进行查找操作，使用双向链表记录值的新旧(链表头部代表最新数据)

get 和 put 时间复杂度都为 O(1)

具体见代码注释

```
struct MyListNode {
    MyListNode* next;
    MyListNode* pre;
    int key;
    int val;
    MyListNode(int k, int v) : key(k), val(v), next(NULL), pre(NULL) {}
};

class LRUCache {
   public:
    LRUCache(int capacity) {
        _head = new MyListNode(0, 0);
        _tail = new MyListNode(0, 0);
        _head->next = _tail;
        _tail->pre = _head;
        _capacity = capacity;
    }

    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;

        MyListNode* node = _map[key];
        updateList(node);

        return node->val;
    }

    void put(int key, int value) {
        // 如果已经存在，更新值和链表
        if (_map.find(key) != _map.end()) {
            MyListNode* node = _map[key];
            node->val = value;
            updateList(node);
            return;
        }

        // 如果满了，移除队尾元素
        if (_capacity == _map.size()) {
            MyListNode* node = _tail->pre;
            _map.erase(node->key);  // 移除 map 中的数据
            removeFromList(node);   // 从链表中删除
        }

        MyListNode* node = new MyListNode(key, value);
        _map[key] = node;    // 插入 map
        insertToHead(node);  // 插入队首
    }

    // 更新链表
    void updateList(MyListNode* node) {
        removeFromList(node);
        insertToHead(node);
    }

    // 把 node 从链表中删除
    void removeFromList(MyListNode* node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    // 把 node 插入链表头部
    void insertToHead(MyListNode* node) {
        node->next = _head->next;
        node->next->pre = node;
        _head->next = node;
        node->pre = _head;
    }

   private:
    int _capacity = 0;
    map<int, MyListNode*> _map;
    MyListNode* _head;
    MyListNode* _tail;
};
```
