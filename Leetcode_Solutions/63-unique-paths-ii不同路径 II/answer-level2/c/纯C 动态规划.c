### 解题思路
动态规划 清清爽爽

### 代码

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int row = 0;
    int col = 0;

    long** dp = (long**)malloc(obstacleGridSize * sizeof(long*));
    for (row = 0; row <= obstacleGridSize - 1; row++)
    {
        dp[row] = (long*)malloc(*obstacleGridColSize * sizeof(long));
    }

    for (row = 0; row <= obstacleGridSize - 1; row++)
    {
        for (col = 0; col <= *obstacleGridColSize - 1; col++)
        {
            if (0 == row && 0 == col) /* 初始情况 */
            {
                if (1 == obstacleGrid[0][0])
                {
                    return 0;
                }
                else
                {
                    dp[0][0] = 1;
                }
            }
            else if (0 == row) /* 边界条件 */
            {
                dp[0][col] = (obstacleGrid[0][col] == 0 && dp[0][col - 1]) ? 1 : 0;
            }
            else if (0 == col) /* 边界条件 */
            {
                dp[row][0] = (obstacleGrid[row][0] == 0 && dp[row - 1][0]) ? 1 : 0;
            }
            else /* 状态方程 */
            {
                dp[row][col] = (1 == obstacleGrid[row][col]) ? 0 : dp[row][col - 1] + dp[row - 1][col];
            }
        }
    }

    return dp[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
```