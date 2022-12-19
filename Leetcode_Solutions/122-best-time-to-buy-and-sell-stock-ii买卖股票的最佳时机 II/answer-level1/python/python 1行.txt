```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(prices[x] - prices[x-1] for x in range(1, len(prices)) if (prices[x] > prices[x-1]))
```
