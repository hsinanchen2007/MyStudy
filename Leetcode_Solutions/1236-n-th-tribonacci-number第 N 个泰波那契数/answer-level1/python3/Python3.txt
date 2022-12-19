```
class Solution:
    def tribonacci(self, n: int) -> int:
        p = [0 for _ in range(max(3,n+1))]
        p[0], p[1], p[2] = 0, 1, 1
        if n > 2:
            for i in range(3, n+1):
                p[i] = p[i-1] + p[i-2] + p[i-3]
        return p[n]
```
