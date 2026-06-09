## 状态定义
#### dp[n][k]: 截止第n天, 当天持有 or 不持有股票时的最大收益(用k来标记)
## 状态转移
#### 第n+1天不持有股票
`dp[n+1][0] = max(dp[n][0], dp[n][1] + num - fee)`
1. 第n天就没持有
2. 第n天持有, 第n+1天卖掉
#### 第n+1天持有股票
`dp[n+1][1] = max(dp[n][1], dp[n][0] - num)`
1. 第n天就已经持有
2. 第n天没持有, 第n+1天买入
# 代码
```
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        int[][] dp = new int[prices.length][2];
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.length; ++i) {
            dp[i][0] = Math.max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = Math.max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[prices.length-1][0];
    }
}
```
时间复杂度: O(n)
空间复杂度: O(n)