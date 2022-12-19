```
class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2: return 0
        if k > len(prices) / 2:
            return self.maxProfit_inf(prices)
            
        dp = [[[0, 0] for _ in range(k + 1)] for _ in range(len(prices))]
        for i in range(len(prices)):
            for j in range(k, 0, -1):
                if i == 0:
                    dp[i][j][0] = 0
                    dp[i][j][1] = -prices[i]
                    continue
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i])

        return dp[len(prices) - 1][k][0]

    def maxProfit_inf(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        dp_i_0, dp_i_1 = 0, float('-inf')

        for price in prices:
            tmp = dp_i_0
            dp_i_0 = max(dp_i_0, dp_i_1 + price)
            dp_i_1 = max(dp_i_1, tmp - price)

        return dp_i_0
```
