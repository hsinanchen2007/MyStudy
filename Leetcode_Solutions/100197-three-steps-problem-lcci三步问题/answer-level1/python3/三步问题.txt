### 解题思路
动态方程：dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

### 代码

```python3
class Solution:
    def waysToStep(self, n: int) -> int:
        if n < 3:
            return n

        dp = [0]*n
        dp[0], dp[1], dp[2] = 1, 2, 4
        for i in range(3,n):
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000007
        return dp[n-1] 


```