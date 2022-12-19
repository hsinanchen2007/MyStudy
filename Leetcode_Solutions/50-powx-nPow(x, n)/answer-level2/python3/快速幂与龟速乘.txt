龟速乘只要把称号改为加号就好，一般用于大整数乘法，避免写高精度乘法
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        t = 0
        m = x
        if n < 0:
            t = -n
        else:
            t = n
        while t > 0:
            if t%2 > 0:
                res = res * m
            m = m * m
            t = t >> 1
        if n < 0:
            return 1/res
        else:
            return res

```
