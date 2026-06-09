### 解题思路
本题是62题的升级版，加上了路障，但依旧是使用**动态规划**解决问题

首先对特殊情况判断是否满足题意，如果满足就将开始位置的值设为1，之后只需访问到终点前一个位置（上或左）即可。

然后对数组进行双重循环，当遇到路障的时候就continue，进行下一轮寻找

如果**i>0**，即**从上往下的路径数**。如果**j>0**，即**从左往右的路径数**。

最终返回终点位置即可

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int dp[][] = new int[m][n];
        //特殊情况判断
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1){
            return 0;
        }
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){//遇到障碍就进行下一轮寻找
                    continue;
                }
                if(i > 0){
                    dp[i][j] += dp[i - 1][j];//从上过来的路径数
                }
                if(j > 0){
                    dp[i][j] += dp[i][j - 1];//从左过来的路径数
                }
            }
        }
        return dp[m - 1][n - 1];
    }
}
```