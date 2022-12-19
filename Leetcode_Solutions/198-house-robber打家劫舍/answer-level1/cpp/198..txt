# dp[0][i]:1~i且第i个不选的最大和
# dp[1][i]:1~i且第i个选上的最大和
# ans=max(dp[0][n-1],dp[1][n-1])
```
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<long long>dp[2];
        int n=nums.size();
        if(n==0)return 0;
        dp[0].resize(n+1);
        dp[1].resize(n+1);
        dp[0][0]=0;
        dp[1][0]=nums[0];
        for(int i=1;i<n;i++){
            dp[0][i]=max(dp[1][i-1],dp[0][i-1]);
            dp[1][i]=dp[0][i-1]+nums[i];
        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};
```