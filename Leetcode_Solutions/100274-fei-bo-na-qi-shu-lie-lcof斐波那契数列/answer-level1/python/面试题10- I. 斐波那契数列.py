### 解题思路
使用dp记录每一次的结果。

### 代码

```python3
class Solution:
    def fib(self, n: int) -> int:
        dp = {}
        if n == 0:
            return 0
        for i in range(0, n+1):
            if i <= 1:
                dp[i] = i
            else:
                dp[i] =(dp[i-1] + dp[i-2])% 1000000007
        return dp[n]
```