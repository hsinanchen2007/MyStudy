```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n
        else:
            dp = [0 for _ in range(n)]
            dp[0] = 1
            dp[1] = 2
            dp[2] = 3
            for i in range(3, n):
                dp[i] = dp[i-1]+dp[i-2]
            return dp[n-1]
```
