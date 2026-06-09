### 解题思路
动态规划dp。
1.二维数组dp[][],空间复杂度O(mn)
2.压缩空间使用一维数组dp[],空间复杂度O(min(m,n))
3.如果不需要原来的数组，可以在原来数组上进行dp, 空间复杂度O(1) 
### 代码

```c 
1
int minPathSum(int** grid, int gridSize, int* gridColSize){
    if(gridSize == 0){
        return 0;
    }
    int dp[gridSize][gridColSize[0]];
    dp[0][0] = grid[0][0];
    for(int i=1;i<gridSize;i++){
        dp[i][0] = dp[i-1][0]+grid[i][0];
    } 
    for(int i=1;i<gridColSize[0];i++){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
    for(int i=1;i<gridSize;i++){
        for(int j=1;j<gridColSize[0];j++){
            dp[i][j] = (dp[i-1][j]<dp[i][j-1]?dp[i-1][j]+grid[i][j]:dp[i][j-1]+grid[i][j]);
        }
    }
    return dp[gridSize-1][gridColSize[0]-1];
}
```
``` 
2
int minPathSum(int** grid, int gridSize, int* gridColSize){
    if(gridSize == 0){
        return 0;
    }
    if(gridSize<=gridColSize[0]){
        int dp[gridSize];
        dp[0] = grid[0][0];
        for(int i=1;i<gridSize;i++){
            dp[i] = dp[i-1]+grid[i][0];
        }
        for(int i=1;i<gridColSize[0];i++){
            dp[0] = dp[0]+grid[0][i];
            for(int j=1;j<gridSize;j++){
                dp[j] = (dp[j]<dp[j-1]?dp[j]+grid[j][i]:dp[j-1]+grid[j][i]);
            }
        }
        return dp[gridSize-1];
    }else{
        int dp[gridColSize[0]];
        dp[0] = grid[0][0];
        for(int i=1;i<gridColSize[0];i++){
            dp[i] = dp[i-1]+grid[0][i];
        }
        for(int i=1;i<gridSize;i++){
            dp[0] = dp[0]+grid[i][0];
            for(int j=1;j<gridColSize[0];j++){
                dp[j] = (dp[j]<dp[j-1]?dp[j]+grid[i][j]:dp[j-1]+grid[i][j]);
            }
        }
        return dp[gridColSize[0]-1];
    }
    return 0;
}
```
```
3
懒得写了，嘻。
```
