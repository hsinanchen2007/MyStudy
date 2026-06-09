121. 买卖股票的最佳时机
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        dp = [[0,0] for _ in range(n)]
        dp[-1][0] = 0
        dp[-1][1] = - float('inf')
        dp[0][0] = 0
        dp[0][1] = - float('inf')
        for i in range(n):
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+ prices[i]) 
            dp[i][1] = max(dp[i-1][1],- prices[i])
        return dp[-1][0]
```
122. 买卖股票的最佳时机 II
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        dp = [[0,0] for _ in range(n)]
        dp[-1][0] = 0
        dp[-1][1] = - float('inf')
        dp[0][0] = 0
        dp[0][1] = - float('inf')
        for i in range(n):
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i])
        return dp[-1][0]
```
123. 买卖股票的最佳时机 III
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        dp = [[[0 for i in range(2)] for i in range(3)] for i in range(n)]
        for k in range(3):
            dp[0][k][1] = -float('inf')
            dp[-1][k][1] = -float('inf')
        for i in range(n):
            for k in range(1, 2+1):

                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i])
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i])
                
        return dp[n-1][2][0]
```
188. 买卖股票的最佳时机 IV
```
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices: return 0
        n = len(prices)
        if k >= n//2:
            res = 0
            for i in range(1,n):
                if prices[i] > prices[i-1]:
                    res += prices[i] - prices[i-1]
            return res
        else:
            dp = [[[0 for i in range(2)]  for _ in range(k+1)] for __ in range(n)]
            for t in range(k+1):
                dp[-1][t][1] = -float('inf')
                dp[0][t][1] = -float('inf')
            for i in range(n):
                for j in range(1,k+1):
                    dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0] - prices[i])
                    dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1] + prices[i])
            return dp[-1][-1][0]
```
309. 最佳买卖股票时机含冷冻期
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0
        if len(prices) == 1: return 0
        n = len(prices)
        dp = [[0 for i in range(2)] for _ in range(n)]
        dp[-1][1] = -float('inf')
        dp[-2][1] = -float('inf')
        dp[0][1] = -float('inf')
        for i in range(n):
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i])
            dp[i][1] = max(dp[i-1][1],dp[i-2][0] - prices[i])
        return dp[-1][0]
```
714. 买卖股票的最佳时机含手续费

```
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        if not prices: return 0
        n = len(prices)
        dp =[ [0,0] for _ in range(n)]
        dp[-1][1] = -float('inf')
        dp[0][1] = -float('inf')
        for i in range(n):
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i] -fee)
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i])
        return dp[-1][0]
```

