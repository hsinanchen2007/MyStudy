### 解题思路
此处撰写解题思路
动态规划就完事了
### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        if(obstacleGrid.length == 0 || obstacleGrid[0].length == 0 || obstacleGrid[0][0] == 1){
            return 0;
        }

        //到当前点的路径有多少
        int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length];
        dp[0][0] = 1;

        //初始化
        for(int i = 1; i < dp.length; i++){
            if(obstacleGrid[i][0] != 1 && dp[i-1][0]==1){
                dp[i][0] = 1;
            }
        }
        for(int i = 1; i < dp[0].length; i++){
            if(obstacleGrid[0][i] != 1 && dp[0][i-1]==1){
                dp[0][i] = 1;
            }
        }

        for(int i = 1;i < dp.length;i++){
            for(int j = 1;j < dp[0].length;j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[dp.length-1][dp[0].length-1];
    }
}
```