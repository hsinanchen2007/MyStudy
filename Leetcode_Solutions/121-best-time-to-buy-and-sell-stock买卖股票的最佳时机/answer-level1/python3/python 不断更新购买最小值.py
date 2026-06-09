```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        res = 0
        min_val = prices[0]
        for i in range(1,len(prices)):
            if prices[i] < min_val:
                min_val = prices[i]
            else:
                res = max(res, prices[i]-min_val)
        return res
```
