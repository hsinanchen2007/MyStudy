### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        dp = [0 for _ in range(N+1)]
        dp[1] = 1
        x = 2
        while x <= N:
            dp[x] = dp[x-1] + dp[x-2]
            x += 1
        return dp[-1] 
```