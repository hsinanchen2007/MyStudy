```
class Solution {
public:
    int dp[60] = {0};

    int integerBreak(int n) {
        if(n <= 2) return dp[n] = 1;
        else if(dp[n] > 0) return dp[n];

        int ans = 1;
        for(int i = 1; i <= n / 2; i++)
        {
            int cur = i * integerBreak(n - i);
            ans = max(max(ans, i * (n - i)), cur);
        }

        return dp[n] = ans;
    }
};
```
