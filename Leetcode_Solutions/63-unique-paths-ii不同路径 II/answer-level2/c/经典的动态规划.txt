从起点开始，无论到达哪个点，当到达这个点时，我们仅考虑上一步，那么只有两种可能：
从上边的格子进入或从左边的格子进入
那么到达该点的方法应该是到达上边那个点的路径数加上到达左边那个点的路径数和
这样就可以利用动态规划，按照从左往右，从上到下依次遍历每一个点，算出到达每个点的路径数目，并返回最后一个点的数目即可
只有一种特殊情况，就是当前点是1，表示有障碍物，那么到达这点的路径数直接赋值为0即可
```
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int i,j;
    int m,n;
    long long int DP[101][101];
    if (obstacleGrid == NULL || obstacleGridSize <= 0 || obstacleGridColSize == NULL)
        return 0;
    m = obstacleGridSize;
    n = obstacleGridColSize[0];
    printf("m = %d, n=%d\n", m, n);
    for (i = 0; i < m; i++) { //DP内存初始化为0
        for (j = 0; j < n; j++)
            DP[i][j] = 0;
    }
    DP[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0; //第一格特殊处理一下
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                DP[i][j] += i > 0 ? DP[i-1][j] : 0; //DP公式
                DP[i][j] += j > 0 ? DP[i][j-1] : 0; //DP公式
            }
        }
    }
    return DP[m-1][n-1];
}
```
