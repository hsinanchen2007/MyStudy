

```python []
class Solution:
    
    def maxProfit(self,prices:List[int])->int:
        min_prices = 2**32-1
        maxprofit = 0
        for i in prices:
            if i<min_prices:
                min_prices = i
            else:
                if i-min_prices>maxprofit:
                    maxprofit = i-min_prices
        return maxprofit
```
