```
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0: return False
        if n == 1: return True
        if n < 0: return False
        while n > 1:
            r = n / 2
            if r != int(r):
                return False
            else:
                n = r
        return True
```
