经典的完全背包问题，对于本题来说，物品体积就是完全平方数，每个价值都为1，总体积为n,求最小价值，完全背包先循环物品，再循环体积，均从小到大，可以用一维数组优化空间
```
class Solution:
    def numSquares(self, n: int) -> int:
        i = 1
        dp = [0x3f for _ in range(n+1)]
        dp[0] = 0
        while i * i <=n:
            for j in range(i*i , n+1):
                dp[j] = min(dp[j],dp[j-i*i] + 1)
            i += 1
        return dp[-1]
```
