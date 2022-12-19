### 解题思路

**总之就是一句话：最大利润=max(前一天的最大利润，今天价格-之前最低价格)
而在最开始的时候，最大利润为0，最低价格就是第一天本身价格**

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lengh = len(prices)
        if lengh <=1: return 0

        min_price = prices[0]
        max_profit = 0

        for i in range(lengh):
            max_profit = max(max_profit, prices[i]-min_price)
            min_price = min(min_price, prices[i])

        return max_profit

```