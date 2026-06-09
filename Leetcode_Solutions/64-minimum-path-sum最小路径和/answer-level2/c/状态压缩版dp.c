### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridColSize[0], n = gridSize;
    int dp[m + 1];
    dp[0] = INT_MAX;
    dp[1] = grid[0][0];
    for (int i = 2; i <= m; i++)
        dp[i] = grid[0][i - 1] + dp[i - 1];
    for (int y = 1; y < n; y++)
        for (int x = 0; x < m; x++)
            dp[x + 1] = MIN(dp[x], dp[x + 1]) + grid[y][x];
    return dp[m];
}
```