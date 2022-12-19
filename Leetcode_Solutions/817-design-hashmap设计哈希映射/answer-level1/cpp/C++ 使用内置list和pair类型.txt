```cpp
class MyHashMap {
private:
    list<pair<int, int>> hashMap[10000];
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &map = hashMap[key % 10000];
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        map.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &map = hashMap[key % 10000];
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &map = hashMap[key % 10000];
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->first == key) {
                map.erase(it);
                return;
            }
        }
    }
};
```