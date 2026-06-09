```
class Solution:
    def climbStairs(self, n: int) -> int:
        f = [1,2]
        for i in range(2,n):
            f.append(f[i-1]+f[i-2])
        return f[n-1]
```
