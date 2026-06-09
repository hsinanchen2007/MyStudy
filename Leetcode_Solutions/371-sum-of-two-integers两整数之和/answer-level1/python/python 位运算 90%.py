```
class Solution(object):
    def getSum(self, a, b):
        if a < 0 < b < abs(a) or b < 0 < a < abs(b) or a * b > 0:
            mark = True
        else:
            mark = False
        while b & 0xffffffff:
            a, b = a ^ b, (a & b) << 1
        return a if mark else a & 0xffffffff
```

