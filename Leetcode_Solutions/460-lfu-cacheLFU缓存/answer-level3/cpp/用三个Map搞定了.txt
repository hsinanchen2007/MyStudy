### 解题思路

这里时间的那个map，不能用time(), 这里只能精确到秒，这里需要c++11特性：std::chrono
显然这里有点偷懒的。
### 代码

```cpp
class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (maps.find(key) != maps.end()) {
            counts[key] ++;
            times[key] = std::chrono::high_resolution_clock::now().time_since_epoch()/ std::chrono::nanoseconds(1);
            return maps[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (_capacity <= 0) {
            return;
        }
        if (maps.find(key) != maps.end()) {
            maps[key] = value;
            counts[key] ++;
            times[key] = std::chrono::high_resolution_clock::now().time_since_epoch()/ std::chrono::nanoseconds(1);
            return;
        } 

        //容量已经满了，需要淘汰掉老得数据
        if (maps.size() == _capacity) {
            int min = INT_MAX;
            int key = -1;
            for (auto iter : counts) {
                if (iter.second < min) {
                    min = iter.second;
                    key = iter.first;
                } else if (iter.second == min) {
                    if (times[iter.first] <= times[key]) {
                        key = iter.first;
                    }
                }
            }

            maps.erase(key);
            counts.erase(key);
            times.erase(key);
        }
        
        maps[key] = value;
        counts[key] ++;
        times[key] = std::chrono::high_resolution_clock::now().time_since_epoch()/ std::chrono::nanoseconds(1);
        return;
    }

private:
    std::map<int, int> maps;
    std::map<int, int> counts;
    std::map<int, uint64_t> times;
    int _capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```