```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        while n>=5:
            res+=n//5
            n//=5
        return res

class Solution:
    def trailingZeroes(self, n: int) -> int:
        p = 0
        while n>=5:
            n = n//5
            p+=n
        return p
```
