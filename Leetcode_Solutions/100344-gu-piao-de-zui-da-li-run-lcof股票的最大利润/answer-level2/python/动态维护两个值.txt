### 解题思路
维护两个值，最大利润值（max_price），最小历史值（min_value）

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<2:
            return 0

        x, y = prices[0], prices[1]
        max_price = y - x
        min_value = min(x, y)

        for i in prices[2:]:
            max_price = max(max_price, i-min_value)
            min_value = min(min_value, i) 

        return max(max_price, 0)
```