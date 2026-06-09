### 思路一：使用额外空间

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();        
        vector<int> tmp(size, 0), res;
        for (auto n : nums) {
            tmp[n - 1] = n;
        }
        for (int i = 0; i < size; ++i) {
            if (tmp[i] - 1 != i) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
```

### 思路二：交换位置
根据数组值为当前下标值加 1 的对应关系，如果不相等，则交换到正确位置。

### 代码
```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();        
        vector<int> res;
        for (int i = 0; i < size; ++i) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < size; ++i) {
            if (nums[i] - 1 != i) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
```

