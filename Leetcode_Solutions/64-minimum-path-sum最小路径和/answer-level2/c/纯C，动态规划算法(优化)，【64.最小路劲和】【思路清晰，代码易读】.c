### 解题思路
方法一：动态规划算法
1, dp[m][n] 每个位置记录到达当前位置最小路径
2, 找出dp[m][n] 和 dp[m-1][n-1] 、dp[m][n-1]、dp[m-1][n-1]之间的关系
3, dp[m][n] = MIN(dp[m-1][n], dp[m][n-1]) + grid[m][n]
4, 优化动态规划，减少空间，只需要 dp[n] 大小数组保存上一行的值即可

### 代码

```c
//方法一：动态规划算法
//1, dp[m][n] 每个位置记录到达当前位置最小路径
//2, 找出dp[m][n] 和 dp[m-1][n-1] 、dp[m][n-1]、dp[m-1][n-1]之间的关系
//3, dp[m][n] = MIN(dp[m-1][n], dp[m][n-1]) + grid[m][n]
//4, 优化动态规划，减少空间，只需要 dp[n] 大小数组保存上一行的值即可

#define     MIN(a, b)   ((a) < (b) ? (a) : (b))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int     i       = 0;
    int     j       = 0;
    int     m       = gridSize;
    int     n       = gridColSize[0];
    int     dp[n];

    memset(dp, 0x00, sizeof(int) * n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((i == 0) && (j == 0))
            {
                //1,第一个点特殊处理
                dp[j] = grid[i][j];
            }
            else if (i == 0)
            {
                //2,第一行特殊处理
                dp[j] = dp[j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                //3,第一列特殊处理
                dp[j] = dp[j] + grid[i][j];
            }
            else
            {
                dp[j] = MIN(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
    }
    return dp[n - 1];
}
```