### 解题思路

哈希表 + 双链表

### 代码

```cpp
class LRUCache {
private:
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        int res;
        if(dict.count(key) > 0) {
            auto it = dict[key];
            res = it->second;
            q.erase(it);
            q.push_front(make_pair(key, res));
            dict[key] = q.begin();
        } else {
            res = -1;
        }
        return res;
    }
    
    void put(int key, int value) {
        if(dict.count(key) > 0) {
            q.erase(dict[key]);
        }
        if(q.size() >= cap) {
            auto p = q.back();
            dict.erase(p.first);
            q.pop_back();
        }
        q.push_front(make_pair(key, value));
        dict[key] = q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```