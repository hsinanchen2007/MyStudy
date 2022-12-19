```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        Len = len(prices)
        if Len < 2:
            return 0 
        res = 0       
        for i in range(Len-1):
            if prices[i] < prices[i+1]:
                res += prices[i+1] - prices[i]
        return res
```
