```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        dp[i]表示凑齐i元最少需要的硬币数
        dp[i] = min(dp[i - coin_j]) + 1 , 当前凑齐i-coin的最少硬币数 + 1
        -1 表示没有可能，但是dp[0] = 0用来设置初始的值
        """
        dp = [-1 for _ in range(amount + 1)]
        dp[0] = 0
        for i in range(1, amount + 1):
            tmp_len = []
            for coin in coins:
                if coin <= i and dp[i - coin] != -1:
                    tmp_len.append(dp[i - coin])
            if tmp_len:
                dp[i] = min(tmp_len) + 1
        return dp[amount]
```
