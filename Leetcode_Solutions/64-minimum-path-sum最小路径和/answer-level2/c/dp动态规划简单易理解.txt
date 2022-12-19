### 解题思路
dp数组记录该点到起始点的最短距离，边界时候单独处理，非边界取上一次计算的最小值加上本点的值即可。思路清晰代码也很简单。dp数组可以使用malloc动态分配即可，偷懒直接申请了一个挺大的空间。时间复杂度是遍历整个二维数组花费的时间。

### 代码

```c
#define min(a,b)(a<b?a:b)

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize,n = *gridColSize;
    int dp[1000][1000];

    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(i==0 && j==0 ){
                dp[i][j] = grid[i][j];
            }
            else if(i == 0){
                dp[i][j] = grid[i][j] + dp[i][j-1];
            }
            else if(j == 0){
                dp[i][j] = grid[i][j] + dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
            
        }
    }
    return dp[m-1][n-1];
}
```