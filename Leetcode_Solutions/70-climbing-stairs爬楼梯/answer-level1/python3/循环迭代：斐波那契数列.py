```python []
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        fib0 = 1
        fib1 = 1
        for i in range(2,n+1):
            temp = fib0
            fib0 = fib1
            fib1 = temp+fib1
        return fib1
```

