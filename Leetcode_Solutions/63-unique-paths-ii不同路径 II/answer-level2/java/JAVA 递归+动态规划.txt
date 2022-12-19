能用动态规划最好还是用动态规划，递归太耗时了，动态规划就是损耗了一点内存，速度很快，因为是记忆性搜索。
```
class Solution {
    /*
    //这是递归的解法，但是这种方法超时，过不了，于是改用动态规划。
    public int dfs(int[][] obstacleGrid ,int row,int col){
    // System.out.println(row);
        if(row >= obstacleGrid.length || col >= obstacleGrid[0].length || obstacleGrid[row][col] == 1  )
            return 0;
        if(row == obstacleGrid.length-1 && col == obstacleGrid[0].length-1)
            return 1;
        return dfs(obstacleGrid,row+1,col) + dfs(obstacleGrid,row,col+1);    
    }
    */
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length];
        if(obstacleGrid.length < 1)
            return 0;
        for(int i = 0;i<obstacleGrid.length;i++){
            if(obstacleGrid[i][0] == 1){
                    dp[i][0] = 0;
                    for(int j = i;j<obstacleGrid.length;j++){
                        dp[i][0] = 0;
                    }
                    break;
                }
            dp[i][0] = 1;
        }
        for(int i = 0;i<obstacleGrid[0].length;i++){
            if(obstacleGrid[0][i] == 1){
                    dp[0][i] = 0;
                    for(int j = i;j<obstacleGrid[0].length;j++){
                        dp[0][i] = 0;
                    }
                    break;
                }
            dp[0][i] = 1;
        }
        for(int i = 1;i<obstacleGrid.length;i++){
            for(int j = 1;j<obstacleGrid[0].length;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}
```
