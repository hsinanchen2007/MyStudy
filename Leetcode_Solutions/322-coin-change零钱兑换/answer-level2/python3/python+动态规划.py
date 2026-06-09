3分钟写dp，30分钟写边界条件。d=====(￣▽￣*)b
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not amount:
            return 0
        res = []
        for i in coins:
            if i <= amount:
                res.append(i)
        coins = res
        if not coins:
            return -1
        a = min(coins)
        b = max(coins)
        if a > amount:
            return -1
        dp = [0 for _ in range(amount+1)]
        for i in coins:
            dp[i] = 1
        def f(dp,a,b,coins):
            for i in range(a,b):
                if i in coins:
                    dp[i] = 1
                else:
                    l = []
                    for j in coins:
                        if i - j > 0 and dp[i - j] != 0:
                            l.append(dp[i - j])
                    if l:
                        dp[i] = min(l) + 1
        f(dp,a+1,b,coins)
        f(dp,b+1,amount+1,coins)
        return dp[-1] if dp[-1] != 0 else -1
```

