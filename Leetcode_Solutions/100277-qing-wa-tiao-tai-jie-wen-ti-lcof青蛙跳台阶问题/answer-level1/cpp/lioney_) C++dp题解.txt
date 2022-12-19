```
class Solution {
public:
    int numWays(int n) {
        if(n<2) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};
```
