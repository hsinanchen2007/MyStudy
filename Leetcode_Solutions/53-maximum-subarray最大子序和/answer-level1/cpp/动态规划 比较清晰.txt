//1.状态：数组size  选择：选或不选
//2.dp[i]=x 表示以nums[i]结尾的连续子数组的最大和为x
//  base case: dp[0]= nums[0]
//3.转移方程：dp[i] = max(dp[i-1]+nums[i], nums[i])

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; ++ i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
```
