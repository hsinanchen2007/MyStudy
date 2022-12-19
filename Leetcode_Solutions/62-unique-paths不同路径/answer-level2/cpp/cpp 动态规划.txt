//1.状态：m n  ；选择：向下或向右
//2.dp[i][j]=x 表示以(i,j)为终点共有x条路径
//  base case: dp[i][0] = 1, dp[0][j] = 1
//3.转移方程：dp[i][j]=dp[i-1][j]+dp[i][j-1]

```
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++ i) {
            for(int j = 1; j < n; ++ j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
