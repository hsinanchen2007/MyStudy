```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        max_p = [0]*len(prices)
        max_p[-1] = prices[-1]
        dp = [0]*len(prices)
        for index in range(len(prices)-2,-1,-1):
            dp[index] = max_p[index+1] - prices[index]
            max_p[index] = max(max_p[index+1],prices[index])
        return max(dp)
```
让右边一直保持最大价格