```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n= obstacleGrid[0].length;
        int [][] dp = new int[m+1][n+1];//扩容二维数组，免去不必要的边界判断
        dp[1][1] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                dp[i][j]+=dp[i-1][j]+dp[i][j-1];//注意要+=，否则dp[1][1]回加不上去
                if(obstacleGrid[i-1][j-1]==1)
                    dp[i][j]=0;
            }
        }
        return dp[m][n];
    }
}
```
