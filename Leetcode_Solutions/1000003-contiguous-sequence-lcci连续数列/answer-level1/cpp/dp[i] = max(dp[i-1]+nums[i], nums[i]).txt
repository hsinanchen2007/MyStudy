### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            maxSum = dp[i] > maxSum ? dp[i] : maxSum;
        }
        return maxSum;
    }
};
```