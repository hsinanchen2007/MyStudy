### 解题思路
此处撰写解题思路

### 代码

```c
#define min(x,y) (x > y ? y : x)
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int col = *gridColSize;
    int dp[col];
    dp[0]= grid[0][0];
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (i == 0 && j != 0) {
                dp[j] = grid[0][j] + dp[j - 1];
            } else if (j == 0 && i != 0) {
                dp[0] = grid[i][0] + dp[0];
            } else if (i != 0 && j != 0) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
    }
    return dp[j - 1];
}
```