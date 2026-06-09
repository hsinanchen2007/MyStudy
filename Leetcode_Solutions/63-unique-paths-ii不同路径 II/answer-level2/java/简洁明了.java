```java    
    class Solution {
        public int uniquePathsWithObstacles(int[][] obstacleGrid) {
            int n = obstacleGrid.length;
            int m = obstacleGrid[0].length;
            //多申请点空间，这样不用考虑边上的问题
            int[][] dp = new int[n+1][m+1];
            //确保动态规划能转起来
            dp[n][m-1] = 1;
            for(int i = n-1; i >= 0; i --) {
                for(int j = m-1; j >=0; j --) {
                    if(obstacleGrid[i][j] == 0) {
                        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                    }else {
                        dp[i][j] =  0;
                    }
                }
            }
            return dp[0][0];
        }
    }