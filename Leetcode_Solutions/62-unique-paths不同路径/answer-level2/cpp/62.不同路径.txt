### 解题思路
动态规划，假设 dp[i][j] 是从（0，0）走到第 i 行第 j 列的路径数量，那么得到 dp[i][j] = dp[i - 1][j] + dp[i][j - 1],要么它是从上一行走下来的，要么它是从同一行左边一个走下来的。
初始化条件是第 0 行，和第 0 列的所有元素路径数为 1，因为在这两条边界时只有一种走法。

### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100];
        dp[0][0] = 1;
        for(int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1];
        }
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};
```