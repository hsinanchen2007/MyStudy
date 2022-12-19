## 解析
本题和62题很像。解法也很类似。只不过要加点判断条件。
## 代码
```java
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0) {
            return 0;
        }
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) {
            return 0;
        }
        int[] dp = new int[col];
        dp[0] = 1;
        for (int i = 1; i < col; i++) {
            if (dp[i - 1] == 0 || obstacleGrid[0][i] == 1) {
                dp[i] = 0;
            } else {
                dp[i] = 1;
            }
        }

        for (int i = 1; i < row; i++) {
            if (dp[0] == 1 && obstacleGrid[i][0] == 0) {
                dp[0] = 1;
            }else {
                dp[0] = 0;
            }

            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }

        }
        return dp[col - 1];
    }


    public int uniquePathsWithObstacles1(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0) {
            return 0;
        }
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) {
            return 0;
        }
        int[][] dp = new int[row][col];
        dp[0][0] = 1;
        for (int i = 1; i < row; i++) {
            if (dp[i - 1][0] == 0 || obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }

        for (int i = 1; i < col; i++) {
            if (dp[0][i - 1] == 0 || obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }

        }
        return dp[row - 1][col - 1];
    }
```