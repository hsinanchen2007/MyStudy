利用minv和p逐步更新计算局部最优，并更新全局最优。

```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices or len(prices) == 0:
            return 0
        p,minv = 0,prices[0]
        for i in range(1,len(prices)):
            minv = min(minv,prices[i-1])
            p = max(p,prices[i]-minv)
        return p
```
