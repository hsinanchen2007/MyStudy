## 状态定义:
`dp[n][k][0]`: 截止第n天, 交易k次的情况下, 且第n天不持有股票的最大收益
`dp[n][k][1]`: 截止第n天, 交易k次的情况下, 且第n天持有股票的最大收益
## 状态方程:
### 持有状态: 
`dp[n][k][0] = max(dp[n-1][k][0], dp[n-1][k-1][1]);`
第n天交易了k次且不持有股票: 
**情况1:** n-1天就交易了k次且不持有股票 
**情况2:** n-1天交易了k-1次且持有股票, 第n天卖掉
### 不持有状态
`dp[n][k][1] = max(dp[n-1][k][1], dp[n-1][k][0]);`
第n天交易了k次且持有股票: 
**情况1:** n-1天就交易了k次且持有股票 
**情况2:** n-1天就交易了k次但不持有股票, 第n天买入

**注意:** 这里假设卖出算一次交易
# 代码
```
class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length <= 1) return 0;
        int times = k;
        int max = 0;
        //退化为无限次问题
        if (k >= prices.length / 2) {
            for (int i = 1; i < prices.length; ++i) {
                if (prices[i] > prices[i-1]) {
                    max += prices[i] - prices[i-1];
                }
            }
            return max;
        }
        //定义状态
        int[][][] dp = new int[prices.length][times+1][2];
        dp[0][0][1] = -prices[0];
        //为不可能出现的情况设置一个很小的值
        for (int i = 1; i <= times; ++i) {
            dp[0][i][0] = ~(1<<21);
            dp[0][i][1] = ~(1<<21);
        }
        //枚举每一天、每天k次、当天是否持有股票的所有情况
        for (int i = 1; i < prices.length; ++i) {
            for (int j = 0; j <= times; ++j) {
                if (j == 0) dp[i][j][0] = 0;
                else dp[i][j][0] = Math.max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]);
                dp[i][j][1] = Math.max(dp[i-1][j][1], dp[i-1][j][0] - prices[i]);
            }
        }
        //得到最大值
        for (int i = 0; i <= times; ++i) {
            max = Math.max(max, dp[prices.length-1][i][0]);
        }
        return max;
    }
}
```
时间复杂度: O(N·K)
空间复杂度: O(N·K)
