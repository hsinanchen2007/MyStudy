```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        //如果开始就有障碍，那走不了
        dp[0][0] = obstacleGrid[0][0]==0 ? 1:0;
        //在单方向行走的过程中，如果遇到障碍，后面的方格就没法到达
        //单向行走的状态转移方程
        for(int i = 1; i < m; i++){
            dp[i][0] = obstacleGrid[i][0]==0&&dp[i-1][0]==1 ? 1:0;
        }
        for(int i = 1; i < n; i++){
            dp[0][i] = obstacleGrid[0][i]==0&&dp[0][i-1]==1 ? 1:0;
        }
        //往下或者往右走的时候，上边或左边是障碍，那么是前一步是障碍的路径数为0
        //往下或者往右走的状态转移方程
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = (obstacleGrid[i-1][j]==0 ? dp[i-1][j]:0) + (obstacleGrid[i][j-1]==0 ? dp[i][j-1]:0);
                }
            }
        }
        return dp[m-1][n-1];
    }
}
```

