### 解题思路
一次遍历：对于每个价格，计算当前最低价格，比较在最低价格买入并在当天卖出所得的利润，再与当前最大利润比较，保留较大者。
动态规划：比前者多使用一倍存储空间，当前价格处的最大利润应该等于 max(前一价格处的最大利润，当前价格减去当前最低价)。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """ one-round traverse
        minPrice = float("inf")
        profit = 0
        for price in prices:
            minPrice = min(minPrice, price)
            profit = max(profit, price - minPrice)
        return profit
        """
        # dynamic programming
        if len(prices) >= 2:
            profits = [0] * len(prices)
            minPrice = prices[0]
            for i in range(1, len(prices)):
                minPrice = min(minPrice, prices[i])
                profits[i] = max(profits[i-1], prices[i] - minPrice)
            return profits[-1]
        else:
            return 0

```