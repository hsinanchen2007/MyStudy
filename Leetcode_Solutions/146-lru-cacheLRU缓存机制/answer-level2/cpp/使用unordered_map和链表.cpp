### 解题思路
维护一个链表做LRU stack，一个unordered_map做key-to-value mapping,另一个unordered_map做key-to-listnode mapping。get()中只需要更新链表；put()中更新所有的信息，可以最后调用get()来更新链表。难点就是要注意在更新链表时考虑全所有的情况，并且更新所有相关的指针，我就是忘记了注释多个叹号的两行，卡了好久。。。太蠢了，以前还写过cache simulator，本以为秒过的。。。

### 代码

```cpp
class LRUCache {
public:
    struct Node {
        int key;
        Node* pre;
        Node* next;
        Node(int a) {
            key = a;
            pre = NULL;
            next = NULL;
        }
    };
    Node* head;         // LRU
    Node* tail;         
    unordered_map<int, int> key_value;
    unordered_map<int, Node*> key_pointer;
    int C;
    
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        C = capacity;
    }
    
    int get(int key) {
        if (key_pointer.find(key) != key_pointer.end()) {
            Node* p = key_pointer[key];
            if (p != tail) {
                if (p != head) {
                    p->next->pre = p->pre;
                    p->pre->next = p->next;
                    p->pre = tail;
                    p->next = NULL;
                    tail->next = p;   // !!!!!
                    tail = p;
                }
                else {
                    p->next->pre = NULL;
                    head = p->next;
                    tail->next = p;          // !!!!!
                    p->pre = tail;
                    p->next = NULL;
                    tail = p;
                }
            }
            return key_value[key];
        }
        else 
            return -1;
    }
    
    void put(int key, int value) {
        key_value[key] = value;

        if (key_pointer.find(key) == key_pointer.end()) {  // not found
            if (key_pointer.size() < C) {         // not full
                if (!tail) {           // empty
                    head = new Node(key);
                    tail = head;
                    key_pointer[key] = tail;
                }
                else {
                    tail->next = new Node(key);
                    tail->next->pre = tail;
                    tail = tail->next;
                    key_pointer[key] = tail;
                }
            }
            else {            // full
                int old_key = head->key;
                key_value.erase(old_key);
                key_pointer.erase(old_key);
                key_pointer[key] = head;
                head->key = key;
                get(key);
            }
        }
        else     // found
            get(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```