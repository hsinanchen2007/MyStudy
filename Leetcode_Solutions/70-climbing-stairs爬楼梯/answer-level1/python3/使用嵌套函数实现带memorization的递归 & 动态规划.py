# 递归
```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0] * (n+1)
        memo[0] = memo[1] = 1
        def climb(n):
            if memo[n] > 0:
                return memo[n]
            else:
                method = climb(n-1) + climb(n-2)
                memo[n] = method
                return method
        return climb(n)
```

# 动态规划
```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0] * (n+1)
        memo[0] = memo[1] = 1
        if n == 1:
            return 1
        else:
            for i in range(2, n+1):
                memo[i] = memo[i-1] + memo[i-2]
            return memo[n]
```

