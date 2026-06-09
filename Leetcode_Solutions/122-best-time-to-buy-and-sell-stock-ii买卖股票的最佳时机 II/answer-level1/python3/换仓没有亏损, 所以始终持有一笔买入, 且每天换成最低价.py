```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = 999999999
        earn = 0
        for p in prices:
            if p > buy:
                earn += p - buy
                buy = p
            if p < buy:
                buy = p
        return earn
```
