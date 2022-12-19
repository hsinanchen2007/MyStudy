
和不同路径1一样的解法，注意跳过障碍
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        if(obstacleGrid.length == 0) return 0;

        int n = obstacleGrid.length;
        int m = obstacleGrid[0].length;

        //起点有障碍，返回0
        if(obstacleGrid[0][0] == 1) return 0;
        //终点有障碍，返回0
        if(obstacleGrid[n-1][m-1] == 1) return 0;

        int[][] dp = new int[n][m];
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //当前点有障碍，跳过
                if(obstacleGrid[i][j] == 1) continue;
                if( i==0 && j==0 )continue;
                if( i==0 && j>0 ){
                    dp[i][j] = obstacleGrid[i][j-1] == 0 ? dp[i][j-1]:0;
                }else if( j==0 && i>0 ){
                    dp[i][j] = obstacleGrid[i-1][j] == 0 ? dp[i-1][j]:0;
                }else{
                    dp[i][j] = (obstacleGrid[i][j-1] == 0 ? dp[i][j-1]:0) 
                            + (obstacleGrid[i-1][j] == 0 ? dp[i-1][j]:0); 
                }
            }
        }
        return dp[n-1][m-1];  
    }
}
```
