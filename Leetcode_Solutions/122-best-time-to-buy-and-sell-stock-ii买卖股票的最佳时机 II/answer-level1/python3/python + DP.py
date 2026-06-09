```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # buy = max(buy, sell - now_val)
        # sell = max(sell, buy + now_val)
        # [7, 1, 5, 3, 6, 4]
        # 7 => buy()

        # buy[i] = max(buy[i - 1], sell[i - 1] - now_val)
        # sell[i] = max(sell[i - 1], buy[i - 1] + now_val)
        # special case
        if len(prices) < 2: return 0
        buy, sell = -prices[0], 0
        for i in range(1, len(prices)):
            price = prices[i]
            temp_buy = buy
            buy = max(buy, sell - price)
            sell = max(sell, temp_buy + price)
        return sell
```