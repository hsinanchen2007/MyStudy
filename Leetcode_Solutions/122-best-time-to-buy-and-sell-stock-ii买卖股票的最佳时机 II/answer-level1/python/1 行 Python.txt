```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(b - a for a, b in zip(prices, prices[1:]) if b > a)
```
本题可以在同一天买入和卖出，因此只要当天票价比昨天的高就可以卖出

