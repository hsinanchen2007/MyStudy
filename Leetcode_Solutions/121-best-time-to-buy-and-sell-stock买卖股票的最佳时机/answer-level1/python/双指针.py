
### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profile = 0
        for price in prices:
            max_profile = max(max_profile, price - min_price)
            min_price = min(min_price, price)
        return max_profile

```