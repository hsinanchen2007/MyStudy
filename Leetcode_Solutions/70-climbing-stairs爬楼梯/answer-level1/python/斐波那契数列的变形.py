```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        a= 1
        b= 2
        for i in range(n - 1):
            a, b = b, a + b
        return a
```
