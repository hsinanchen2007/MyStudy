```
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<vector<int>> dp(nums.size(),vector<int>(2,0));
        int ans=0;
        int n= nums.size();
        dp[0][0]=0;
        dp[0][1]=nums[0];
        dp[1][0]=nums[0];
        dp[1][1]=nums[1];
        for(int i=2;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        ans = max(dp[n-1][0],dp[n-1][1]);
        return ans;
    }
};
```
