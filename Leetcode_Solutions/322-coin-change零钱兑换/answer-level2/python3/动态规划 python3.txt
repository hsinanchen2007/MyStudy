```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        max_size = amount + 1
        dp = [max_size] * max_size
        dp[0] = 0
        for i in range(1, max_size):
            min_dpi = dp[i]
            for c in coins:
                if i >= c:
                    tmp = dp[i - c] + 1
                    if tmp < min_dpi:
                        min_dpi = tmp
            dp[i] = min_dpi
        if dp[amount] < max_size:
            return dp[amount]
        else:
            return -1
```
