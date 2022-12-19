### 解题思路
动态规划解法，第n个台阶需要的跳法可通过第n-1个台阶跳一步，也可通过第n-2个台阶跳两步得到。因此状态转移方程就为dp[n] = dp[n-1] + dp[n-2]

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        if n<=1:
            return 1
        dp = [0] * (n+1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range(3,n+1):
            dp[i] = (dp[i-1] + dp[i-2])%1000000007
        return dp[-1]
```