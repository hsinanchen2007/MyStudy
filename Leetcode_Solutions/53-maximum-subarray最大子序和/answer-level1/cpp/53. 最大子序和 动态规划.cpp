### 解题思路
动态规划，一维数组形式的转化方程，直接使用原数组作为动态规划数组，nums[i]表示以第i位元素作为最后一位，最大子序和。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]+nums[i]>nums[i])nums[i]=nums[i-1]+nums[i];
            m = max(nums[i],m);
        }
        return m;
    }
};
```