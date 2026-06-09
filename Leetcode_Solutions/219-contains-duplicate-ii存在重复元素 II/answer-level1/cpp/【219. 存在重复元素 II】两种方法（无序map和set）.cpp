## 思路一：利用map
### 代码
```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < size; ++i) {
            if (umap.count(nums[i]) > 0) {
                if (i - umap[nums[i]] <= k) {
                    return true;
                } else {
                    umap[nums[i]] = i;
                }
            } else {
                umap[nums[i]] = i;
            }
        }
        return false;
    }
};
```

## 思路二：利用set
散列表来维护k大小的滑动窗口。
### 代码
```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_set<int> uset;
        for (int i = 0; i < size; ++i) {
            if (uset.count(nums[i]) > 0) return true;
            uset.insert(nums[i]);
            if (uset.size() > k) {
                uset.erase(nums[i - k]);//nums[i - k]移除窗口
            }
        }
        return false;
    }
};
```

