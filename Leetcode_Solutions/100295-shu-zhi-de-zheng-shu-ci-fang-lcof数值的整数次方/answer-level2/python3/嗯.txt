```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        if x == 0 : return res 
        if n == 0: return  1
        mark = 0
        if n< 0: mark = 1; n = -n
        cur = 1
        exp = x
        while n:
            if n & 1: res *= exp 
            exp = exp*exp
            n >>=1
        return res if not mark else 1/res
```
