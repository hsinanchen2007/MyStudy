class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        int[][] dp=new int[n][m];
        for(int i=0;i<m;i++){
            if(obstacleGrid[0][i]==0)
                dp[0][i]=1;
            else
                break;
        }
        for(int j=0;j<n;j++){
             if(obstacleGrid[j][0]==0)
                dp[j][0]=1;
            else
                break;
        }       
        for(int x=1;x<n;x++)
            for(int y=1;y<m;y++){
                if(obstacleGrid[x][y]==0)
                   dp[x][y]=dp[x-1][y]+dp[x][y-1];
            }
        return dp[n-1][m-1];
    }
}