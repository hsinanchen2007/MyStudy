### 解题思路
动态规划 清清爽爽

### 代码

```c
static inline int min(int a, int b)
{
    return a < b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    /*
     * 状态方程：dp[i][j] = grid[i][j] + MIN{dp[i - 1][j] + dp[i][j - 1]}
     * 边界情况：dp[i][0] = grid[i][0]; dp[0][j] = grid[0][j] 
     * 初始条件：dp[0][0] = grid[0][0]
     */
    int row = 0;
    int col = 0;

    int** dp = (int**)malloc(gridSize * sizeof(int*));
    for (row = 0; row <= gridSize - 1; row++)
    {
        dp[row] = (int*)malloc(*gridColSize * sizeof(int));
    }

    for (row = 0; row <= gridSize - 1; row++)
    {
        for (col = 0; col <= *gridColSize - 1; col++)
        {
            if (0 == row && 0 == col)
            {
                dp[0][0] = grid[0][0];
            }
            else if (0 == row)
            {
                dp[0][col] = grid[0][col] + dp[0][col - 1]; 
            }
            else if (0 == col)
            {
                dp[row][0] = grid[row][0] + dp[row - 1][0]; 
            }
            else
            {
                dp[row][col] = grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
            }
        }
    }

    return dp[gridSize - 1][*gridColSize - 1];
}
```