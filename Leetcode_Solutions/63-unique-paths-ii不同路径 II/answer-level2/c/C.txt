int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long dp[obstacleGridSize][obstacleGridColSize[0]];
    for (int i = 0; i < obstacleGridSize; i++) {
        for (int j = 0; j < obstacleGridColSize[0]; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j > 0) {
                dp[0][j] = dp[0][j-1];
                continue;
            }
            if (j == 0 && i > 0) {
                dp[i][0] = dp[i-1][0];
                continue;
            }
            if (j == 0 && i == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[obstacleGridSize-1][obstacleGridColSize[0]-1];
}
![Snipaste_2019-12-09_10-14-28.png](https://pic.leetcode-cn.com/f6eb336b6242bb85644ccfe131460ce31f4e9e91597739e56dbbf028c3d012dd-Snipaste_2019-12-09_10-14-28.png)
