动态规划，
到达当前[i][j]方格的路径总和等于[i-1][j]+[i][j-1]的和，如果当前方格是障碍物，则说明不可到达，
记作[i][j]=0;
于是代码可得
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length;//获取行数
        if(n == 0)return 0;
        int m = obstacleGrid[0].length;//获取列数
        if(m == 0)return 0;
        int[][] dp = new int[n][m];
        if(obstacleGrid[0][0] == 1)return 0;
        for (int i = 0; i < m; i++) {
            if(obstacleGrid[0][i] != 1)
                dp[0][i] = 1;
            else {
                dp[0][i] = 0;
                break;//如果遇到障碍，说明下面的都到不了，
            }
        }
        for (int i = 0; i < n; i++) {
            if(obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            else {
                dp[i][0] = 0;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else dp[i][j] = 0;
            }
        }
        return dp[n - 1][m - 1];
    }

}
