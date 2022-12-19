多次买卖，即找出直到最后一天，你能交易赚到的所有的钱，如果prices[i]>prices[i-1]则交易，否则不交易。

```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        p = 0
        for i in range(1,len(prices)):
            tmp = prices[i] - prices[i-1]
            if tmp > 0:
                p += tmp
        return p
```
