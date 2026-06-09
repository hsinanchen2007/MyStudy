```cpp
const int mod = 1e9 + 7;
class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            if (dp[i] >= mod) dp[i] -= mod;
        }
        return dp[n];
    }
};
```