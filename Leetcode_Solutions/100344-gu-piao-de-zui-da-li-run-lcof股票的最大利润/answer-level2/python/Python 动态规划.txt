```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = [i for i in prices]
        # dp表示当前买入的最低价

        for i in range(1, len(prices)):
            dp[i] = min(dp[i - 1], dp[i])
            # 当前买入的最低价取于上一次买入的最低价与当前最低价的最小值
        
        # 下面这一步可以放到上面进行，但是分开看得更直观
        max_val = 0
        for buy, sell in zip(dp, prices):
            max_val = max(max_val, sell - buy)
        
        return max_val
```