### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 2) {
            return 0;
        }
        int   n  = prices.length;
        //dp思路 dp[i][j] 表示第i天 j表示第i天的状态 0 不持有 1 持有 2 冷冻期
        //则状态转移方程为:
        //dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //dp[i][1] = Math.max(dp[i-1][2] - prices[i], dp[i-1][1]);
        //dp[i][2] = dp[i-1][0];
        int[][] dp = new int[n][3];
        //定义初始状态
        dp[0][0] = 0;
        dp[0][1] = - prices[0];
        dp[0][2] = 0;

        //一次遍历
        for (int i = 1; i < n; i++) {
             dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i]);
             dp[i][1] = Math.max(dp[i-1][2] - prices[i], dp[i-1][1]);
             dp[i][2] = dp[i-1][0];
        }

        return Math.max(dp[n-1][0], dp[n-1][2]);
    }
}
```