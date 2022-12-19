直接上代码
```
def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)<2: return 0
        maxBen = 0
        i, j = 0, 1
        for j in range(1, len(prices)):
            if prices[j] >= prices[i]:
                maxBen = max(maxBen, prices[j]-prices[i])
            else:
                i = j
        return maxBen
```
