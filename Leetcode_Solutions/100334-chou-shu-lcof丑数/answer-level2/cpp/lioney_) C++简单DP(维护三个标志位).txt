```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int i2 = 0, i3 = 0, i5 = 0;
        dp[0] = 1;
        for(int i=1; i<n; i++) {
            dp[i] = min(dp[i2] * 2, min(dp[i3] * 3, dp[i5] * 5));
            i2 += (dp[i] == dp[i2] * 2);
            i3 += (dp[i] == dp[i3] * 3);
            i5 += (dp[i] == dp[i5] * 5);
        }
        return dp[n-1];
    }
};
```
