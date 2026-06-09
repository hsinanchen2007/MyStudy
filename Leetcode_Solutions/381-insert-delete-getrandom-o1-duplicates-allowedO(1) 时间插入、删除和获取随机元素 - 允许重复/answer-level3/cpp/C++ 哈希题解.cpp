# 思路：
1，利用哈希结构`unordered_map<int, unordered_set<int> > value_indices`存储值对应的下标集合
2，利用`vector<int> nums`存储所有的数字
3，删除的时候利用尾部向前替换待删除的数字，然后进行尾部删除，使得删除操作可以做到O(1)

```C++ []
class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int> > value_indices;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = value_indices.count(val) == 0;
        nums.push_back(val);
        value_indices[val].insert(nums.size() - 1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (value_indices.count(val) == 0) return false;
        int tail = nums.back();
        if (tail == val) {
            value_indices[val].erase(nums.size() - 1);
            nums.pop_back();
        } else {
            int ind = *value_indices[val].begin();
            nums[ind] = tail;
            value_indices[tail].erase(nums.size() - 1);
            value_indices[tail].insert(ind);
            value_indices[val].erase(ind);
            nums.pop_back();
        }
        if (value_indices[val].empty()) {
            value_indices.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int s = nums.size();
        int r = rand() % s;
        return nums[r];
    }
};
```

![image.png](https://pic.leetcode-cn.com/cbda850a09b0a2a6851a627293d3c12760757a8f10382dfa3183881700dd7bbb-image.png)
