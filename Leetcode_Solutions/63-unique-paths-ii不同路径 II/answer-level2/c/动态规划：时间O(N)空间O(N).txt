### 解题思路
初始化边界基础值，动态规划，增加条件判断
if(obstacleGrid[i][j] == 1)
    dp[i][j] = 0;
else
    dp[i][j] = dp[i-1][j] + dp[i][j-1];

### 代码

```c
#define MAX 100

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    // rows: obstacleGridSize
    // column: obstacleGridColSize[0]
    if(obstacleGridSize == 0)
        return 0;
    long long dp[MAX][MAX] = {0};
    int i = 0; 
    int j = 0;
    for(;i < obstacleGridSize; i++){
        if(obstacleGrid[i][0] == 1)
            break;
        else
            dp[i][0] = 1;
    }
    
    for(; j < obstacleGridColSize[0]; j++){
        if(obstacleGrid[0][j] == 1)
            break;
        else
            dp[0][j] = 1;
    }

    for(i = 1; i < obstacleGridSize; i++){
        for(j = 1; j < obstacleGridColSize[0]; j++){
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}
```