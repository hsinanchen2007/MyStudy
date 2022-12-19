```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==1 or x==0:
            return x
        
        x0=x
        x1=0
        num=x
        while True:
            x1=float(x0-(x0*x0-num)/(2*x0))
            x1_int=int(x1)
            if x1_int*x1_int<=num:
                return x1_int
            x0=x1
```