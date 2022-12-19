## 思路一：基于vector
### 代码
```c++
class MyHashSet {
    vector<bool> hash;
public:
    /** Initialize your data structure here. */
    MyHashSet() : hash(1000000, false) {
        
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};
```

## 思路二：哈希桶
### 代码
```c++
#define MAX_LEN 100000
class MyHashSet {    
    vector<int> bucket[MAX_LEN];//通过数组实现
    
    //返回bucket index
    int getIndex(int key) {
        return key % MAX_LEN;
    }

    int getPos(int key, int index) {
        for (int i = 0; i < bucket[index].size(); ++i) {
            if (bucket[index][i] == key) {
                return i;
            }
        }
        return -1;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos < 0) {
            bucket[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        if (pos >= 0) {
            bucket[index].erase(bucket[index].begin() + pos);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = getIndex(key);
        int pos = getPos(key, index);
        return pos >= 0;
    }
};
```

