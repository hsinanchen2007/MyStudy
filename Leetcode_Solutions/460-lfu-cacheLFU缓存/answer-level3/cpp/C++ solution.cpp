### 解题思路
写的复杂了
### 代码

```cpp
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        time_counter++;
        if (count.find(key) == count.end()) {
            return -1;
        } else {
            count[key]++;
            use_time[key] = time_counter;
            return pos[key];
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        time_counter++;
        if (pos.find(key) == pos.end()) {
            if (use < capacity) {
                pos[key] = value;
                count[key] = 1;
                use_time[key] = time_counter;
                use++;
            } else {
                vector<int> to_evit;
                int min_use_time = INT_MAX;
                auto it = count.begin();
                for (; it != count.end(); it++) {
                    if (it->second < min_use_time) {
                        min_use_time = it->second;
                        to_evit.clear();
                        to_evit.push_back(it->first);
                    } else if (it->second == min_use_time) {
                        to_evit.push_back(it->first);
                    }
                }
                int lru = INT_MAX;
                int evit_key;
                for (int i = 0; i < to_evit.size(); i++) {
                    if (use_time[to_evit[i]] < lru) {
                        lru = use_time[to_evit[i]];
                        evit_key = to_evit[i];
                    }
                }
                //printf("evit: %d", evit_key);
                count.erase(evit_key);
                pos.erase(evit_key);
                use_time.erase(evit_key);
                pos[key] = value;
                count[key] = 1;
                use_time[key] = time_counter;
            }
        } else {
            pos[key] = value;
            use_time[key] = time_counter;
            count[key]++;
        }
    }
private:
    map<int, int> count;
    map<int, int> pos;
    map<int, int> use_time;
    int capacity;
    int time_counter = 0;
    int use = 0;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```