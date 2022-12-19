dp[i][j]表示从(1, 1)到(i, j)的方案数。
显然只能从左边和上边的位置转移到当前位置，所以有:
dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1]

```
class Solution {
public:
  int dp[105][105]; 
  int uniquePaths(int m, int n) {
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[n][m];
  }
};
```
