求最优解，很容易想到动态规划。

最初的设想是设 dp[i] 是**粉刷到第 i 个房子要花费的最少成本**，想办法找到 dp[i] 和前面的 dp[i-1] 之间的关系。
很快发现 dp[i] 需要分3种情况来讨论：第 i 个房子用的拿一种颜色。
假如房子 i 用的红色，就只用知道房子 i-1 用蓝色的 dp[i-1] 和用绿色的 dp[i-1] 中谁较小就行了。
可以知道无论 dp[i] 还是 dp[i-1] 都有三种情况：最后一个房子用的哪种颜色。
于是**用二维数组 dp[i][j] 保存状态，j = 0,1,2。分别表示第 i 个房子用红、蓝、绿粉刷**。

这样，就很容易得到状态转移方程：
dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
简化：
dp[i][j] = Math.min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + costs[i][j];

边界条件：
只用知道 dp[0][0]、dp[0][1]、dp[0][2] 就可以了，分别等于 costs[0][0]、costs[0][1]、costs[0][2]。

知道了 状态转移方程 和 边界条件，很容易得出代码：

```
class Solution {
    public int minCost(int[][] costs) {
        if(costs.length == 0)
            return 0;
        int n = costs.length;
        int[][] dp = new int[n][3];
        
        for(int i = 0; i < 3; i++)
            dp[0][i] = costs[0][i];
        
        for(int i = 1; i < n; i++)
            for(int j = 0; j < 3; j++)
                dp[i][j] = Math.min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + costs[i][j];
            
        return Math.min(Math.min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    }
}
```

