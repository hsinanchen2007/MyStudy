## 思路
### 代码
```c++
class MyHashMap {
    vector<int> hash;
public:
    /** Initialize your data structure here. */
    MyHashMap() : hash(1000000, -1) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hash[key] = value;        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hash[key] = -1;
    }
};
```
