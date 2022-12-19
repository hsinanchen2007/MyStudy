## 思路：vector+map

### 代码
```c++
class RandomizedSet {
    unordered_map<int, int> umap;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (umap.count(val) > 0) {
            return false;
        }
        nums.push_back(val);
        umap[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (umap.count(val) > 0) {
            int last = nums.back();//最后一个数
            nums[umap[val]] = last;//删除位置换位最后一个数
            umap[last] = umap[val];//更新最后一个数位置映射为删除数映射
            nums.pop_back();//删除最后一个数
            umap.erase(val);//删除当前数映射
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
```

