与62题相似；
1. 考虑dp的含义：用于记录步数；
2. 考虑障碍物的特殊情况；遇到障碍物时，方格得置0；
3. 考虑边界只能走一步；
4. 考虑中间联系dp[i][j]=dp[i-1][j]+dp[i][j-1];

```
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        if(obstacleGrid==null||m==0||n==0) return 0;
        int[][] dp=new int[m][n];
        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0]=1;
        //考虑边界
        for(int i=1;i<m;i++) {
            if(obstacleGrid[i][0]==0)
            dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i]==0)
            dp[0][i]=dp[0][i-1];
        }
        //考虑中间
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
```
