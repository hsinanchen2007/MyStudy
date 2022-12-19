```
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        bb = dividend / divisor
        cc = int(bb)
        if bb > 2**31 - 1:
            return(2**31 -1)
        elif bb < (-2**31):
            return(-2**31)
        else:
            return(cc)
```
