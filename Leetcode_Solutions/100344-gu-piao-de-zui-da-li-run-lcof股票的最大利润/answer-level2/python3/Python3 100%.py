```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        min_p = prices[0]
        res = 0
        for price in prices:
            min_p = min(price,min_p)
            res = max(res,price-min_p)
        return res
```
