
删除的时候，把待删除元素和数组最后的元素交换，避免移动N个元素，同时 hashmap 只需要更新一个 key。

```cpp
class RandomizedSet {
private:
    unordered_map<int, int> dict;
    vector<int> v;
    default_random_engine re;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.find(val) == dict.end()) {
            v.push_back(val);
            dict.emplace(val, v.size() - 1);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = dict.find(val);
        if(it != dict.end()) {
            int x = *v.rbegin();
            dict[x] = it->second;
            swap(v[it->second], v[v.size() - 1]);
            v.pop_back();
            dict.erase(it);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(v.size() == 0)
            return 0;
        int n = re() % v.size();
        return v[n];
    }
};
```
52 ms, 击败 98.39 %

或者：

### 代码

```cpp
class RandomizedSet {
private:
    unordered_map<int, int> dict;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val) > 0)
            return false;
        vec.push_back(val);
        dict[val] = vec.end()-vec.begin()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.count(val) == 0)
            return false;
        int idx = dict[val];
        int end = vec.back();
        swap(vec[idx], vec[vec.size()-1]);
        dict[end] = idx;
        vec.pop_back();
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }
};

```