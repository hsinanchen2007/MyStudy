### 解题思路
1. 确定dp的含义：dp是个二维数组，代表着 在点(i,j)能拿到的最大礼物数量
2. 找状态转移方程：dp[i][j] = grid[i][j] + max(dp[i-1][j],dp[i][j-1]) 因为只能下走或者右走
3. 确定初始值：由于i-1>=0 j-1>=0所以在第一行、第一列应该为初值，（因为从第一行和第一列只有一种走法就是直着走）

### 代码

```c
int maxValue(int** grid, int gridSize, int* gridColSize){
    int **dp;
    dp = (int**)malloc(sizeof(int*)*gridSize);
    for (int i=0;i<gridSize;i++)
        dp[i] = (int*)malloc(sizeof(int)*gridColSize[i]);
    dp[0][0] = grid[0][0];
    for (int i=1;i<gridSize;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int i=1;i<gridColSize[0];i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];
    for (int i=1;i<gridSize;i++){
        for (int j=1;j<gridColSize[0];j++){
            if (dp[i-1][j]>dp[i][j-1])
                dp[i][j] = grid[i][j] + dp[i-1][j];
            else
                dp[i][j] = grid[i][j] + dp[i][j-1];
        }
    } 
    return dp[gridSize-1][gridColSize[0]-1];
}
```