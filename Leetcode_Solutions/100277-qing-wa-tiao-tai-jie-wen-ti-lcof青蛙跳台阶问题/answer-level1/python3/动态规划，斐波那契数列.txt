### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 1

        dp = []
        dp = [0 for _ in range (n+1)]
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range (3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[-1]%1000000007
```