```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices)<2:
            return 0
        prof=0
        lowp = prices[0]
        highp = lowp
        for i,p in enumerate(prices):
            if p<highp:
                prof+=(highp-lowp)
                lowp=p
            elif i==len(prices)-1:
                prof+=max(0,prices[i]-lowp)
            highp=p
        return prof
```
