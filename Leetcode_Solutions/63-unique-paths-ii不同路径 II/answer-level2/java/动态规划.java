### 解题思路
一、初始化路线结果集
二、针对首行和首列，若前面为可通过（上一行或列的标记为1）标记为1，否则标记为0
三、循环计算下一格可通过的线路数

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        //行
        int l=obstacleGrid.length;
        //列
        int r=obstacleGrid[0].length;
        int [][] dp=new int[l][r];
        dp[0][0]=obstacleGrid[0][0]==1?0:1;
        if(dp[0][0]==0){
            return 0;
        }
        
        //初始化行
        for (int i = 1; i < l; i++) {
            dp[i][0]=(dp[i-1][0]==1&&obstacleGrid[i][0]==0)?1:0;
        }
        //初始化列
        for (int i = 1; i < r; i++) {
            dp[0][i]=(obstacleGrid[0][i]==0&&dp[0][i-1]==1)?1:0;
        }
        for (int i = 1; i < dp.length; i++) {
            for (int j = 1; j < dp[i].length; j++) {
                if(obstacleGrid[i][j]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[l-1][r-1];
    
    }
    
}
```