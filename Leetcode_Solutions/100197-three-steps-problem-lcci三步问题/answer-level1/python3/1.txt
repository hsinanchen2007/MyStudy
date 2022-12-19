### 解题思路

### 代码

```python3
class Solution(object):
    def waysToStep(self, n):
        dp = [0]*n
        dp[0] = 1
        if n == 2:
            dp[1] = 2
        if n == 3:
            dp[1] = 2
            dp[2] = 4
        if n > 3:
            dp[1] = 2
            dp[2] = 4
            for i in range(3,n):
                dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])% 1000000007
        return dp[n-1] 

```