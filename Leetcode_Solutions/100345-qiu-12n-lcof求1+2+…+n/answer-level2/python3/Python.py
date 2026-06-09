```
class Solution:
    def sumNums(self, n: int) -> int:
        if n == 1: return 1
        return n + self.sumNums(n-1)
```
