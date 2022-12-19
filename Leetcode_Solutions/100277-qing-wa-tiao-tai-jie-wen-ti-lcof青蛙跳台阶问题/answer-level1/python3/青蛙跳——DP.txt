### 解题思路
此处撰写解题思路
dp[i] = dp [i-1] + dp[i-2]
### 代码

```python3
class Solution:
    def numWays(self, n: int) -> int:
        dp = {}
        dp[0] = 1
        dp[1] = 1
        for i in range(2,n+1):
            dp[i] = dp[i-1]+dp[i-2]
        return dp[n]%1000000007
```