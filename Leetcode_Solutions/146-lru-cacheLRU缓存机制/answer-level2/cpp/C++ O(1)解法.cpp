为了让put操作达到O(1), 采用链表实现，这样在表头插入新节点仅需有限次操作， 无需向数组一样花费O(N)去向后搬移数组元素；
为了让get操作达到O(1), 采用哈希表存储key值到链表节点的映射关系，C++ STL中的unordered_map是采用哈希实现的；
为降低链表的维护难度，首尾各放置一个空节点；
```cpp
class XListNode {
public:
    int key, value;
    XListNode *prev, *next;
    XListNode(int ik = 0, int iv = 0) {
        key = ik;
        value = iv;
        prev = NULL;
        next = NULL;
    }
    void pick() {
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
        prev = NULL;
        next = NULL;
    }
    void insertAfter(XListNode *node) {
        if (!node) return; 
        prev = node;
        next = node->next;
        prev->next = this;
        next->prev = this;
    } 
};

class LRUCache {
public:
    XListNode mHead, mTail;
    XListNode *head = &mHead;
    XListNode *tail = &mTail;
    int mCapacity;
    int count = 0;
    unordered_map<int, XListNode*> mMap;
    LRUCache(int capacity) {
        mCapacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = mMap.find(key);
        if (it == mMap.end()) {
            return -1;
        } else {
            auto p = it->second;
            p->pick();
            p->insertAfter(head);
            return p->value;
        }
    }
    
    void put(int key, int value) {
        auto it = mMap.find(key);
        if (it != mMap.end()) {
            auto p = it->second;
            p->value = value;
            get(p->key);
        } else {
            auto *p = new XListNode(key, value);
            mMap[key] = p;
            p->insertAfter(head);
            if (count < mCapacity) {
                count++;
            } else {
                auto p = tail->prev;
                if (p != head) {
                    mMap.erase(mMap.find(p->key));
                    p->pick();
                    delete p;
                }
            }
        }
    }
};
```