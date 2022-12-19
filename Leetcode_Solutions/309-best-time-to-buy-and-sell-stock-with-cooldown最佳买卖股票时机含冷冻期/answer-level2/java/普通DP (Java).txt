## 状态定义: 
dp[n][k][t]: 表示截止第n天, 当天卖出/不卖出(用k标记), 持有/不持有(用t标记)的情况下最佳收益
## 状态方程
### 不卖出+不持有
`dp[n+1][0][0] = max(dp[n][0][0], dp[n][1][0])`
1. 昨天就没卖也没持有
2. 昨天卖掉了
### 没卖出+持有
`dp[n+1][0][1] = max(dp[n][0][1], dp[n][0][0] - num)`
1. 昨天就没卖出且持有
2. 昨天没卖出也没持有, 今天买入
### 卖出
`dp[n+1][1][0] = dp[n][0][1] + num`
昨天没卖出且持有, 今天卖出
# 代码
```
class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int[][][] dp = new int[prices.length][2][2];
        dp[0][0][1] = -prices[0];
        dp[0][1][0] = ~(1<<20);
        for (int i = 1; i < prices.length; ++i) {
            dp[i][0][1] = Math.max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]);
            dp[i][0][0] = Math.max(dp[i-1][0][0], dp[i-1][1][0]);
            dp[i][1][0] = dp[i][0][1] + prices[i];
        }
        return Math.max(dp[prices.length-1][1][0], dp[prices.length-1][0][0]);
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)