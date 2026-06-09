```
//与62题不同的就是：1、初始化赋值的时候遇到障碍物就退出，后面的就不需要赋值了
                   2、for循环的时候遇到障碍物就直接将障碍物处的路径置为0；
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int dp[][] = new int[m][n];
        for(int i =0;i<m;i++){
            if(obstacleGrid[i][0]!=1){
                dp[i][0] =1;
            }else{
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]!=1){
                dp[0][j]=1;
            }else{
                break;
            }
        }
        for(int i =1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j] = dp[i-1][j] + dp [i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
```
