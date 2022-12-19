### 解题思路
code:
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        price = prices[0]
        max1 = 0
        max2 = 0
        for t in prices[1:]:
            x = t - price
            price = t
            max2 = max2 + x if max2 > 0 else x
            max1 = max(max1, max2)
        return max1
```