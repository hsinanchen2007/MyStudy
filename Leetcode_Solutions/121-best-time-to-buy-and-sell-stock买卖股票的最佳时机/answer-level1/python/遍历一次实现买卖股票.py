```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice, maxProfit = -1, 0
        for i in range(len(prices)):
            if prices[i] < minPrice or minPrice == -1:
                minPrice = prices[i]
            if prices[i] - minPrice > maxProfit:
                maxProfit = prices[i] - minPrice
        return maxProfit

```
