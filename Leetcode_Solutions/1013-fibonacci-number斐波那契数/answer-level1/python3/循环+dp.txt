#### 将递归改为循环
```
class Solution:
    def fib(self, N: int) -> int:
        if N == 0:
            return 0
        if N == 1:
            return 1
        num1 = 0
        num2 = 1
        n = 2
        while n <= N:
            num = num1 + num2
            num1 = num2
            num2 = num
            n += 1
        return num
```
#### dp算法
```
class Solution:
    def fib(self, N: int) -> int:
        if N == 0:
            return 0
        if N == 1:
            return 1
        dp = [0]*(N + 1)
        dp[0] = 0
        dp[1] = 1
        n = 2
        while n <= N:
            dp[n] = dp[n-1] + dp[n-2]
            n += 1
        return dp[-1]
```
