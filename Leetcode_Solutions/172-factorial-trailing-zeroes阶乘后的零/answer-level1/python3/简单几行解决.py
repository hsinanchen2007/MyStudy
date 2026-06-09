```
class Solution:
    def trailingZeroes(self, n: int) -> int:
        import math
        if n<=0:
            return 0
        special =  math.log(n,5)
        res = 0
        for x in range(0,int(special)):
            x = x+1
            res+=int(n//5**x)
        return res
```
