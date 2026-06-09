python可以处理大数。

```
class Solution(object):
    def numSteps(self, s):
        a = int(s, 2)
        res = 0
        while a > 1:
            if a % 2:
                a += 1
            else:
                a >>= 1
            res += 1
        return res
```
