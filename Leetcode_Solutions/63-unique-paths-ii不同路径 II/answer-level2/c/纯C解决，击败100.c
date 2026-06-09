在不同路径I的基础上加了障碍这一条件，注意一下障碍对边界条件和状态转移方程的影响就行。

还有就是返回的时候，目的地上面是否有障碍也要判断一下。

直接上代码，不懂的欢迎留言~
```
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    //if(obstacleGridSize==1||*obstacleGridColSize==1)
        //if(obstacleGrid[obstacleGridSize-1][*obstacleGridColSize-1])
        //return 0;
    unsigned int **dp=(unsigned int **)malloc(sizeof(unsigned int *)*(obstacleGridSize));//建立dp数组
    int i,j;
    for(i=0;i<obstacleGridSize;i++)
        dp[i]=(unsigned int *)malloc(sizeof(unsigned int)*(*obstacleGridColSize));
    dp[0][0]=1;
    for(i=1;i<obstacleGridSize;i++)//初始化第一列
        //if(obstacleGrid[i-1][0]!=1)
        dp[i][0]=(obstacleGrid[i-1][0]<1?dp[i-1][0]:0);
    for(j=1;j<*obstacleGridColSize;j++)//初始化第一行
    //if(obstacleGrid[0][j-1]!=1)
        dp[0][j]=(obstacleGrid[0][j-1]<1?dp[0][j-1]:0);
    for(i=1;i<obstacleGridSize;i++)
        for(j=1;j<*obstacleGridColSize;j++)
        dp[i][j]=(obstacleGrid[i-1][j]<1?dp[i-1][j]:0)+(obstacleGrid[i][j-1]<1?dp[i][j-1]:0);
    return obstacleGrid[obstacleGridSize-1][*obstacleGridColSize-1]<1?dp[obstacleGridSize-1][*obstacleGridColSize-1]:0;
}
```
