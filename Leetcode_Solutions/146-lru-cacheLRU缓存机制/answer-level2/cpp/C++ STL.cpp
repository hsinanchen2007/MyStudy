```c++
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!m.count(key)) return -1;
        // move to list head
        // dest.splice(dest pos, src, src pos)
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            m[key]->second = value;
            return;
        }
        if (m.size() >= cap) {
            auto e = l.back();
            l.pop_back();
            m.erase(e.first);
        }
        auto it = l.insert(l.begin(), {key, value});
        m[key] = it;
    }

private:
    int cap = 0;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    // l stores (key, value), key is stored for deletion
    list<pair<int, int>> l;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```