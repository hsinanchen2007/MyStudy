动态规划状态机：dp[i][k][1]/dp[i][k][0]表示第i天剩k次交易机会的时候持有/没持有股票
当天持有可能是前一天持有或者今天买入：dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-price[i])
当前没持有可能是前一天没持有或者今天卖出：dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+price[i])
初始状态，i=-1时还没开始，利润为0：dp[-1][k][0] = 0，不可能持有dp[-1][k][1] = -inf
初始状态，k=0没有交易机会，利润为0：dp[i][0][0] = 0，不可能持有dp[i][0][1] = -inf
最终返回，最后一天卖出得到的利润：dp[n-1][K][0]


```
class Solution:
    def maxProfit(self, k, prices):


        if not prices:
            return 0

        # 买卖交易至少要两天，如果k超过n//2，那就等于没限制次数了
        if k > len(prices) // 2:
            return self.maxProfit_k_inf(prices)

        max_k = k
        dp = [[[0 for _ in range(2)] for _ in range(max_k+1)] for _ in range(len(prices))]

        for i in range(len(prices)):
            for k in range(max_k, 0, -1):
                if i - 1 == -1:
                    dp[i][k][1] = max(-float('inf'), -prices[i])
                    dp[i][k][0] = 0
                else:
                    if k - 1 == 0:
                        dp[i][k][1] = max(dp[i - 1][k][1],  -prices[i])
                    else:
                        dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i])
                    dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i])

        return dp[len(prices)-1][max_k][0]

    def maxProfit_k_inf(self, prices):
        dp_i_1 = -float('inf')
        dp_i_0 = 0

        for i in range(len(prices)):
            dp_i_1 = max(dp_i_1, dp_i_0 - prices[i])
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i])

        return dp_i_0
```


