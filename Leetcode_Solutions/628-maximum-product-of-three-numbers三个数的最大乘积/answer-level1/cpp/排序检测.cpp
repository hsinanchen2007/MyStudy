### 解题思路
首先对数组排序，然后分三种情况
sz = nums.size()
1. 全为非负数，返回nums[sz - 1] * nums[sz - 2] * nums[sz - 3]
2. 全为负数或0，返回同上
3. 正负均有，返回结果可能为2最大负数+1个最大正数或者或者3个最大正数
经过进一步分析，确定即是求nums[sz - 1] * nums[0] * nums[1] 与 nums[sz - 1] * nums[sz - 2] * nums[sz - 3]之间的最大值

### 代码

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int val1 = nums[sz - 1] * nums[0] * nums[1];
        int val2 = nums[sz - 1] * nums[sz - 2] * nums[sz - 3];
        return max(val1, val2);
    }
};
```