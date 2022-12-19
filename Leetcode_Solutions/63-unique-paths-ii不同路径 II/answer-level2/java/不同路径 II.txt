### 解题思路
走到第(i, j)格的方法为走到第(i - 1, j)格的方法 + 走到第(i, j - 1)格的方法。某一格是障碍怎么办？那么走到这一格的方法就为0.

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;
        if (n == 0) {
            return 0;
        }
        int m = obstacleGrid[0].length;
        if (m == 0) {
            return 0;
        }
        int[][] dp = new int[n][m];
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) {
                        dp[i][j] += dp[i - 1][j];
                    }
                    if (j > 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
}
```