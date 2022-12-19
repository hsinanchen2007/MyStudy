### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        if len(prices) == 0:
            return ans
        
        minPrice = prices[0]
        
        for stock in prices:
            ans = max(ans, stock - minPrice)
            minPrice = min(minPrice, stock)
        
        return ans
```