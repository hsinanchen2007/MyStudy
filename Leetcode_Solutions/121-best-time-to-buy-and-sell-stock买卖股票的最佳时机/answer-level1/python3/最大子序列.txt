### 解题思路
计算每天减前一天的diff，转化为最大子序列问题

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        priceDiff = [0]
        priceDiff += [prices[i] - prices[i-1] for i in range(1, len(prices))]
        income = 0
        best = 0
        for price in priceDiff:
            income = max(income + price, price)
            best = max(best, income)
        return best
```