这个方法真的牛X好吧，完美诠释动态规划
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:return 0
        k = 2
        n = len(prices)
        dp = [[[0 for i in range(2)] for i in range(k+1)] for i in range(n)]
        # 设 base_case
        for i in range(n):
            for k in range(k+1):
                dp[-1][k][1] = float("-inf")
                dp[i][0][1] = float("-inf")
        for i in range(n):
            for k in range(2,0,-1):
                dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
                dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
        return dp[n-1][2][0]
```
