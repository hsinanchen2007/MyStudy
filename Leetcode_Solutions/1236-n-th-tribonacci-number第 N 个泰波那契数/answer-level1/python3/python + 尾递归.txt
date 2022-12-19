```
class Solution:
    def tribonacci(self, n: int) -> int:
        def digui(n,a,b,c):
            if n == 0:
                return a
            elif n == 1:
                return b
            elif n == 2:
                return c
            else:
                return digui(n-1,b,c,a + b +c)
        ans = digui(n,0,1,1)
        return  ans
```
