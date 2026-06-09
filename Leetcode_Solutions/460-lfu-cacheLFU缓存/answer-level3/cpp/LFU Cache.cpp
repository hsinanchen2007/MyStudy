### 解题思路
LFU Cache

### 代码

```cpp
struct Node {
    int cnt, time, key, value;
    Node(int cnt, int time, int key, int value):cnt(cnt), time(time), key(key), value(value){}
    bool operator < (const Node& n) const {
        return cnt == n.cnt ? time < n.time : cnt < n.cnt;
    }
};

class LFUCache {
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        Node cache = it -> second;
        S.erase(cache);
        cache.cnt += 1;
        cache.time = ++time;
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) 
        {
            if (key_table.size() == capacity) 
            {
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            Node cache = Node(1, ++time, key, value);
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else 
        {
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};




/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```