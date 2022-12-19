```
class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for(int i=2; i<=n; i++) {
            dp[i] = (dp[i-1] + m) % i;     // dp[i]表示当圆圈中有i个数字时，最后剩下的数字的下标(这里下标和数字相等)
        }
        return dp[n];
    }
};
```
