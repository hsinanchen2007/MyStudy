首先找出平方根的上下界，接着使用二分搜索整数平凡根。
```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x==0:
            return 0
        b=2
        while x>=b**2:
            b=b*2
        a=b//2
        while b-a>1:
            c=(a+b)//2
            if x>c**2:
                a=c
            elif x<c**2:
                b=c
            else:
                return c
        return a   
```
