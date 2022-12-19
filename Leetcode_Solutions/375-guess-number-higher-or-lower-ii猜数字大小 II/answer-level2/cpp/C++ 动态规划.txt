```
class Solution {
public:
    const int INF = 1e8;
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, INF));
        for (int i = 0; i <= n; ++i) {
            dp[i][i] = 0;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n && i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = min(i + dp[i + 1][j], j + dp[i][j - 1]);
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
```

![image.png](https://pic.leetcode-cn.com/15672876c3b470be948f1b4c905c1069c74e5b529295287aa7e4456c03d84298-image.png)
