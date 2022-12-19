### 解题思路
此处撰写解题思路

### 代码

```c
long uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int i = 0,j = 0;
    long **dp = (long**)malloc(sizeof(long*)*obstacleGridSize);
    for(i = 0;i < obstacleGridSize;i++){
        dp[i] = (long*)malloc(sizeof(long)*(*obstacleGridColSize));
    }
    for(i = 0;i < obstacleGridSize;i++){
        for(j = 0;j < *obstacleGridColSize;j++){
            if(1 == obstacleGrid[i][j]){
                dp[i][j] = 0;
            }
            else{
                if(i == 0&&j == 0){
                    dp[0][0] = 1;
                }
                if(i == 0&&j > 0){
                    dp[0][j] = dp[0][j-1];
                }
                if(j == 0&&i > 0){
                    dp[i][j] = dp[i-1][j];
                }
                if(i > 0&&j > 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
    }
    return dp[i-1][j-1];
}
```