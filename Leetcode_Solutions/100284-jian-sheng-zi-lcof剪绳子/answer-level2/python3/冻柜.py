```
class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [0] * (n+1)
        if n == 2: return 1
        if n == 3: return 2
        dp[2] = 2
        dp[3] = 3
        dp[4] = 4
        if n <=4: return dp[n]
        for i in range(5, n+1):
            dp[i] = dp[i-3]*3
        return dp[-1]
```
