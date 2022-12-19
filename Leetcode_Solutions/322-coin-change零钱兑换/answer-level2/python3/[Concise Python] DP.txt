```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0] + [-1] * amount
        for i in range(1, amount+1):
            candidate = [dp[i-coin] + 1 for coin in coins if i-coin >= 0 and dp[i-coin] >= 0]
            if candidate:
                dp[i] = min(candidate)
        return dp[-1]
```

