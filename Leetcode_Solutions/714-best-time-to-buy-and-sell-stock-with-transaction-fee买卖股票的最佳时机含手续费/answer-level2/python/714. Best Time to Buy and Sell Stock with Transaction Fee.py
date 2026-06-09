
```
class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        _lowest, result = prices[0], 0
        for i in range(1, len(prices)):
            # find lowest point
            if _lowest > prices[i]:
                _lowest = prices[i]
            # minus transaction fee
            elif _lowest < prices[i] - fee:
                result += prices[i] - _lowest - fee
                _lowest = prices[i] - fee

        return result
```
