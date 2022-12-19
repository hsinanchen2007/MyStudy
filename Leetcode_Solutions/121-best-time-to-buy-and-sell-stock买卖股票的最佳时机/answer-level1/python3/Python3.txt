### 解题思路
找每个数字的最侧最小值, 计算一次候选最大利润

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit, min_price = 0, float('inf')
        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price-min_price)
        return max_profit
```