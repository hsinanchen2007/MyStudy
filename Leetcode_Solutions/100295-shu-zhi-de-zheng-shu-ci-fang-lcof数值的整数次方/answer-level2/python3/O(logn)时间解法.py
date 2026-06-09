```
class Solution(object):
    def myPow(self, x, n):
        if n == 0: return 1
        if n < 0:
            return 1.0/self.myPow(x,-n)
        result = 1
        while(n):
            if n & 0x1:
                result *= x
            x *= x
            n = n >> 1
        return result

```
