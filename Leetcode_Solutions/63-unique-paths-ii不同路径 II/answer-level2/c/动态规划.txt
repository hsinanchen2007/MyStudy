```
/*动态规划： 使用dp[i][j] 来表示该点是否是可达的。 可达的为1，不可达的为0；
首先不考虑有障碍物的情况，然后再考虑有障碍物的情况，总共是四种情况，然后分别进行
判断。
*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
   if(obstacleGridSize < 1  || *obstacleGridColSize < 1) {
       return 0;
   }
   long dp[100][100] = {0};
   if(obstacleGrid[0][0] == 1) {
       return 0;
   }
   for(int i = 0; i < obstacleGridSize; i++) {
       for(int j = 0; j < *obstacleGridColSize; j++) {
           if(i == 0 && j == 0) {
               dp[i][j] = 1;
           } else if(i != 0 && j == 0) {
               dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j];
           } else if(i == 0 && j != 0) {
               dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i][j - 1];
           } else {
               dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
           }
       }
   }
    return dp[obstacleGridSize - 1][*obstacleGridColSize - 1];
}
```
