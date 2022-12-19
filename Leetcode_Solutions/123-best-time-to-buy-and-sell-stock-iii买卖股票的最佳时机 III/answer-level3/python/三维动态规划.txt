```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2: return 0
        max_k = 2
        dp = [[[0, 0] for _ in range(max_k + 1)] for i in range(len(prices))]
        for i in range(len(prices)):
            for j in range(max_k, 0, -1):
                if i == 0:
                    print(len(prices),i,j)
                    dp[i][j][0] = 0
                    dp[i][j][1] = -prices[i]
                    continue
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i])

        return dp[len(prices) - 1][max_k][0]
        
```
