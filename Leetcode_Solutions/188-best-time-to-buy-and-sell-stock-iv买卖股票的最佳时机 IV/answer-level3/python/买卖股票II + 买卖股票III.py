### 解题思路
k > len(prices) // 2 说明无限交易次数，用 II 的方法直接套
否则用 III 的方法直接套

### 代码

```python3
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices or not k:
            return 0
        res = 0
        row = len(prices)
        if k > row // 2:
            for i in range(1, row):
                if prices[i] > prices[i-1]:
                    res += prices[i] - prices[i-1]
            return res
        else:
            col = k + 1
            dp = [[0 for _ in range(col)] for _ in range(row)]
            for j in range(1, col):
                minCost = prices[0]
                for i in range(1, row):
                    minCost = min(minCost, prices[i] - dp[i-1][j-1])
                    dp[i][j] = max(dp[i-1][j], prices[i] - minCost)
            return dp[-1][-1]
```