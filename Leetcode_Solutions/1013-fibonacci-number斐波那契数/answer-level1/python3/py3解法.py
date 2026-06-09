```
class Solution:
    def fib(self, N: int) -> int:
        r = 0
        n1,n2 =0,1
        if N==0:
            return 0
        if N==1:
            return 1
        for i in range(2, N+1):
            r = n1+n2
            n1,n2=n2,r
        return r
```
