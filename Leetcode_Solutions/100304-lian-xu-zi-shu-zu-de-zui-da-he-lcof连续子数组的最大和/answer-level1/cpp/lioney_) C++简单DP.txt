```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), res = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1; i<n; i++) {
            if(dp[i-1] > 0)   // 实际的递推关系：nums[i] + dp[i-1] > nums[i] 是否成立
                dp[i] = dp[i-1] + nums[i];
            else 
                dp[i] = nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};
```
