### 解法一: 暴力解法
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_p = 0
        for i in range(0, len(prices)-1):
            for j in range(i+1, len(prices)):
                max_p = max((prices[j]-prices[i]), max_p)
        return max_p
```
### 解法二: 判断当前最小价格以及最大收益
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices or len(prices)==1: return 0
        min_price , max_profit = prices[0], 0

        for i in range(0, len(prices)-1):
            min_price  = min(prices[i], min_price)
            max_profit = max(prices[i+1]-min_price, max_profit)
        return max_profit
```