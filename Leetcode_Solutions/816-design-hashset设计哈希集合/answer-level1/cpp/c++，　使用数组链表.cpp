### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyHashSet {
private:
    vector<list<int>> dict;
    const int key_factor = 2049;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        dict.resize(key_factor);
    }
    
    void add(int key) {
        int index = key  % key_factor;
        if (dict[index].empty()) {
            dict[index].insert(dict[index].begin(), key);
        } else {
            auto& lst = dict[index];
            auto iter = lst.begin();
            while (iter != lst.end()) {
                if (*iter == key) {
                    return;
                }
                ++iter;
            }
            if (iter == lst.end()) {
                lst.insert(lst.end(), key);
            }
        }
    }
    
    void remove(int key) {
        auto iter = FindKeyPostion(dict, key);
        if (iter != dict[key % key_factor].end()) {
            dict[key % key_factor].remove(key);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto iter = FindKeyPostion(dict, key);
        if (iter == dict[key % key_factor].end()) {
            return false;
        }
        return true;
    }

    list<int>::iterator FindKeyPostion(vector<list<int>>& dict, int key) {
        int index = key % key_factor;
        auto& lst = dict[index];
        if (lst.empty()) {
            return lst.end();
        }
        auto iter = lst.begin();
        while (iter != lst.end()) {
            if (*iter == key) {
                break;
            }
            ++iter;
        }
        return iter;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```