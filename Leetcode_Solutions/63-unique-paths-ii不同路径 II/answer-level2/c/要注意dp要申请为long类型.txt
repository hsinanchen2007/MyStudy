### 解题思路
此处撰写解题思路

### 代码

```c
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int row = obstacleGridSize;
    int col = obstacleGridColSize[0];
    long* dp = (long*)malloc(row * col* sizeof(long));
    memset(dp, 0, row*col*sizeof(long));

    if((obstacleGrid[0][0] == 1) || (obstacleGrid[row-1][col-1] == 1)) return 0;

    for(int i=0;i<row;i++){
        if(obstacleGrid[i][0] != 1){
            dp[i*col + 0] = 1;
        }else{break;}
    }

    for(int i=0;i<col;i++){
        if(obstacleGrid[0][i] != 1){
            dp[0*col + i] = 1;
        }else{break;}
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
           if(obstacleGrid[i][j] == 1){
               dp[i*col +j] = 0;
           } else{
               dp[i*col +j] = dp[(i-1)*col +j]+dp[i*col +j-1];
           }
        }
    }
    int result = dp[(row-1) *col + col -1];
    free(dp);
    return result;
}
```