### 解题思路
解题思路

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length;
        int column = obstacleGrid[0].length;
        int[][] dp = new int[row][column];
        if (obstacleGrid[0][0] == 1) {
            return 0;
        } else {
            dp[0][0] = 1;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else if (i == 0) {
                    dp[i][j] = (obstacleGrid[i][j - 1] == 1) ? 0 : dp[i][j - 1];
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                    }
                } else if (j == 0) {
                    dp[i][j] = (obstacleGrid[i - 1][j] == 1) ? 0 : dp[i - 1][j];
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                    }
                } else {
                    if (obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j - 1] == 1) {
                        dp[i][j] = 0;
                    } else if (obstacleGrid[i - 1][j] == 1) {
                        dp[i][j] = dp[i][j - 1];
                    } else if (obstacleGrid[i][j - 1] == 1) {
                        dp[i][j] = dp[i -1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
        }

        if (obstacleGrid[row - 1][column - 1] == 1) {
            return 0;
        }
        return dp[row - 1][column - 1];
    }
}
```