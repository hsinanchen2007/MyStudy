```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        res=abs(dividend)//abs(divisor)
        if dividend<=0 and divisor>0 or dividend>=0 and divisor<0:
            res=-res
        if res<-2**31:
            return -2**31
        if res>2**31-1:
            return 2**31-1
        return res
```
