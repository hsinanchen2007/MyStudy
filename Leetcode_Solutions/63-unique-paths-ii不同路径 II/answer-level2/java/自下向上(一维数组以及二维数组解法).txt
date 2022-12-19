# 自下向上：二维数组
时间复杂度是O(row * col), 空间复杂度为O(row * col)
```
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        // 考虑终点是否是障碍物
        if (obstacleGrid[row - 1][col - 1] == 1) {
            return 0;
        }
        // 初始化最后一行和最后一列
        int[][] memo = new int[row][col];
        memo[row - 1][col - 1]= 1;
        for (int i = row - 2;i >= 0; i --) {
            if (obstacleGrid[i][col - 1] != 1) {
                memo [i][col - 1] = memo[i + 1][col - 1];
            }
        }
        for (int i = col - 2; i >= 0; i --) {
            if (obstacleGrid[row - 1][i] != 1) {
                memo[row - 1][i] = memo[row - 1][i + 1];
            }
        }

        for (int r = row - 2; r >= 0; r --) {
            for (int c = col -2; c >= 0; c --) {
                if (obstacleGrid[r][c] != 1) { // 注意障碍物
                    memo[r][c] = memo[r][c + 1] + memo[r + 1][c];
                }
            }
        }
        return memo[0][0];
    }
```
# 自下向上：一维数组
时间复杂度是O(row * col), 空间复杂度降低为O(col)
```
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
    int row = obstacleGrid.length;
    int col = obstacleGrid[0].length;
    // 终点是障碍物
    if (obstacleGrid[row - 1][col -1] == 1) {
        return 0;
    }
    int[] dp = new int[col];
    dp[col - 1] = 1;
    for (int i = col - 2; i >= 0; i --) {
        if (obstacleGrid[row - 1][i] != 1) { // 考虑最后一行是障碍物的情况
            dp[i] = dp[i + 1];
        }
    }

    for (int r = row - 2; r >= 0; r --) {
        // 考虑最后一列是障碍物的情况
        dp[col - 1] = obstacleGrid[r][col -1] == 1 ? 0 : dp[col - 1];
        for (int c = col - 2; c >= 0; c --) {
            if (obstacleGrid[r][c] != 1) {
                dp[c] = dp[c] + dp[c + 1];
            } else { // 遇到障碍物要清0
                dp[c] = 0;
            }
        }
    }
    return dp[0];
}
```

