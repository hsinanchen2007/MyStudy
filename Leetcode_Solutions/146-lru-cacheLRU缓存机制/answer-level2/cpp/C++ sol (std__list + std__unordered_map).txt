### 解题思路
执行用时 :84 ms, 在所有 C++ 提交中击败了99.89%的用户.

1. LRU 的原理十分简单，但是写代码的时候需要特别注意操作iterator
2. 我们在存储it的时候，一定要注意不能在存储它之后再对list进行操作，否则会破坏iterator：
```cpp
    cache.push_front(node);
    node->it = cache.begin(); // update iterator right after updated iterator in cache
```

### 代码

```cpp
struct Node {
    Node(int key, int val) : key(key), val(val) {}

    int key{-1};
    int val{-1};
    list<Node*>::iterator it{};
};

class LRUCache {
private:
    unordered_map<int, Node*> m;
    list<Node*> cache;
    int capacity{1};

public:
    LRUCache(int capacity) : capacity(capacity < 1 ? 1 : capacity) { }
    
    int get(int key) {
        auto it = m.find(key);
        if (m.end() == it) {
            return -1;
        }

        int val = it->second->val;
        put(key, val);

        return val;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (m.end() != it) {
            cache.splice(cache.begin(), cache, it->second->it);
            it->second->val = value;
        } else {
            if (cache.size() == capacity) {
                Node* lastNode = cache.back();
                int deleteKey = lastNode->key;
                
                cache.pop_back(); delete lastNode;
                m.erase(deleteKey);
            }

            Node* node = new Node(key, value);
            cache.push_front(node);
            node->it = cache.begin(); // update iterator right after updated iterator in cache
            m[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```