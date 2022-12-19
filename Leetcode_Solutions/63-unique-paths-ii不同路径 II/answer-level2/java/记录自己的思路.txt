### 解题思路
定义最优解结构：令dp[i][j]表示(0,0)到(i,j)不同路径的数量。
递推公式分析：
到(i,j)这个点，可能是由(i-1,j)到达的，也可能由(i,j-1)到达，即dp[i][j]跟dp[i-1][j]和dp[i][j-1]有关
稍微画下图，很显然，他们的关系是dp[i][j] = dp[i-1][j]+dp[i][j-1] (i >=1,j >= 1)。
**上述过程是主要的递推过程，现在解决边界问题。**
对于i = 0，dp[i][j] = dp[i][j-1];
对于j = 0，dp[i][j] = dp[i-1][j];(当然，上述边界递推的起始条件dp[0][0]是已知，至于他的值emm下面会说)

ok，到现在为止还没有加上有障碍物的这个限制条件，那么现在加上这个条件，产生的影响就是这个点是此路不通。emm简而言之，如果(i,j)的值为1，那么dp[i][j] = 0，所以只要在上述所有的递推公式中加上这个限制条件即可(～￣▽￣)～

最后，还要加上一些特殊情况(不要问为什么我知道这些情况，当然是在WA之后。。。)：
1. 如果start(起始点)的值为1，则最终结果为0.
2. 如果finish(终点)的值为1，则最终结果为0.

那么，现在还差dp[0][0]这个已知条件，很显然，根据上面的叙述，如果(0,0)处有障碍物，那么dp[0][0] = 0；如果没有障碍物的话，可以从dp[i][j]的定义上看，从(0,0)到(0,0)是有路可走，那么说明dp[0][0] = 1； over~

贴上代码：
``` Java
public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        // 特殊情况
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        // 边界
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1];
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
        // 递推
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
```
### 总结
又是核平的一天~