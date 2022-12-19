```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), res = INT_MIN;
        vector<int> dp(n+1);
        for(int i=1; i<=n; i++) {
            dp[i] = max(dp[i-1]+nums[i-1], nums[i-1]);
            res = max(dp[i], res);
        }
        return res;
    }
};
```
