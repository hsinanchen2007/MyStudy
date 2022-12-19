## 思路一：利用vector
### 代码
```c++
class TwoSum {
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); ++i) {
            umap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int t = value - nums[i];
            if (umap.count(t) > 0 && umap[t] != i) {
                return true;
            }
        }
        return false;
    }
};
```

## 思路二：利用无序set
注意重复元素
### 代码
```
class TwoSum {
    unordered_multiset<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            int n = value - *it;
            if (n == *it && nums.count(n) > 1) return true;
            if (n != *it && nums.count(n) > 0) return true;
        }
        return false;
    }
};
```

