执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :37.1 MB, 在所有 java 提交中击败了25.31%的用户
```
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid == null || obstacleGrid.length < 1 || obstacleGrid[0].length < 1)
            return 0;
        int row = obstacleGrid.length;
        int col = obstacleGrid[0].length;
        if(obstacleGrid[row-1][col-1] == 1)
            return 0;
        int[] dp = new int[col];
        for(int i = 0; i < col; i++){
            if(obstacleGrid[0][i] == 0){
                dp[i] = 1;
            }
            else{
                break;
            }
        }
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }
                else if(j != 0){
                    dp[j] = dp[j-1]+dp[j];
                }
            }
        }
        return dp[col-1];
    }
}
```
