### 递归
```python
class Solution:
    def climbStairs(self, n: int) -> int:
        ## 递归
        if n == 1: return 1
        if n == 2: return 2
        return self.climbStairs(n-1)+self.climbStairs(n-2)
```

### 迭代 空间 O(n)
```python
        dp = [1]*n
        if n >= 2: dp[1] = 2
        for i in range(2,n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n-1]
```
### 迭代 空间 O(1)
```python
        if n == 1: return 1
        first, second = 1, 2
        for i in range(3, n+1):
            second, first = first+second, second
        return second
```
