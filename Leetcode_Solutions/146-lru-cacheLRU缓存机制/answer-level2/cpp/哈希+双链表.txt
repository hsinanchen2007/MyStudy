用map去映射，用key去对应节点的地址就好了。在大神的指导写出了应该是O(1)时间复杂度的代码，但是map貌似比unordered_map在这题要快。。。
```
struct Node {
    int val;
    int key;
    Node *next;
    Node *prev;
    Node(int v, int k) : val(v), key(k), next(nullptr), prev(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int, Node *> m;
    int c;
    Node *tmp;
    Node *head;
    Node *tail;
public:
    LRUCache(int capacity) {
        m.clear();
        c = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        tmp = m[key];
        if (tmp) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tail->prev->next = tmp;
            tmp->prev = tail->prev;
            tmp->next = tail;
            tail->prev = tmp;
            return tmp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            tmp->val = value;
            return;
        }
        tmp = new Node(value, key);
        m[key] = tmp;
        tail->prev->next = tmp;
        tmp->prev = tail->prev;
        tmp->next = tail;
        tail->prev = tmp;
        --c;
        if (c < 0) {
            tmp = head->next;
            head->next = tmp->next;
            tmp->next->prev = head;
            m[tmp->key] = nullptr;
            delete tmp;
            tmp = nullptr;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
