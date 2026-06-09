```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        price = sys.maxsize
        total_profit = 0
        profit = 0
        for i in range(len(prices)):
            if prices[i] < price:
                price = prices[i]
                total_profit += profit
                profit = 0
            else:
                if prices[i] - price >= profit:
                    profit = prices[i] - price
                else:
                    total_profit += profit
                    profit = 0
                    price = prices[i]
        total_profit += profit
        return total_profit
```
