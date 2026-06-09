参照了别人的动态规划算法，并做了一点点改良。
```
class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        if d * f < target:
            return 0
        if d * f == target or (d == 1 and f > target):
            return 1
        dp = [[0]*1001 for _ in range(31)]
        for i in range(1,min(f, target)+1):
            dp[1][i] = 1
        mod = 10**9+7
        for i in range(2, d+1):
            for j in range(i, f*i+1):
                k = 1
                while (j - k >= 0 and k <= f):
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k])%mod
                    k += 1
        return dp[d][target]
```
