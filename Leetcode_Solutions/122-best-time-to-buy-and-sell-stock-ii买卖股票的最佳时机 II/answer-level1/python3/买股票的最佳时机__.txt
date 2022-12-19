只考虑后一天的数值是否大于前一天的数值，如果大于则将两天的插值算做利润里，若果不大于则跳过。
```
class Solution:
    def maxProfit(self,prices):
        maxprofit=0
        if (len(prices))<=1:
            return maxprofit
        else:
            for i in range(len(prices)-1):
                if prices[i]<prices[i+1]:
                    maxprofit+=prices[i+1]-prices[i]
            return maxprofit
```
