### 解题思路
记录一个股票的最低价，在此最低价时买入，并在之后卖出的股票与其差值最大才有可能获得最大利润。
遍历股票价格数组，每次比较当前股票与当前最低价股票的差值是否大于当前最大利润，如果是，则更新最大利润。
否则，比较当前股票价格是否小于最低股票价格，如果是，则更新最低股票价格。

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        low_prices = prices[0]
        max_profit = 0
        for i in range(1, len(prices)):
            if prices[i] - low_prices > max_profit:
                max_profit = prices[i] - low_prices
            if prices[i] < low_prices:
                low_prices = prices[i]
        return max_profit
```