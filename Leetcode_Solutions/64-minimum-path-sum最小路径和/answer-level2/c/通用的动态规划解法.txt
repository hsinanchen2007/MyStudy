### 解题思路
dp[m][n] = Min(dp[m - 1][n], dp[m][n - 1]) + grid[m][n];

### 代码
```c
int Min(int a, int b) {
    return (a > b) ? b : a;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int dp[gridSize][*gridColSize];

    dp[0][0] = grid[0][0];
    for (int i = 1; i < gridSize; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    
    for (int j = 1; j < *gridColSize; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int m = 1; m < gridSize; m++) {
        for (int n = 1; n < *gridColSize; n++) {
            dp[m][n] = Min(dp[m - 1][n], dp[m][n - 1]) + grid[m][n];
        }
    }

    return dp[gridSize - 1][*gridColSize - 1];
}
```