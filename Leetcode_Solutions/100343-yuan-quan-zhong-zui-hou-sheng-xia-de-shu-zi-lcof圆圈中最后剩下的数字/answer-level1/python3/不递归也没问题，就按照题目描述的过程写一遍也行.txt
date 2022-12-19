```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        L = [i for i in range(n)]
        last = 0
        while len(L) > 1:
            index = (last + m - 1) % len(L)
            L.pop(index)
            last = index
        return L[0]
```
