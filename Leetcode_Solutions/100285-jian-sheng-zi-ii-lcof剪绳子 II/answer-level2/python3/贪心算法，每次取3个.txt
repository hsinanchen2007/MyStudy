```
class Solution:
    def cuttingRope(self, n: int) -> int:
        a = [0, 1, 1, 2, 4]
        if n < 0:  return False
        if n <= 4:  return a[n]
        res = 1
        while(n>=5):
            n -= 3
            res *= 3
        res *= n
        return res % (pow(10, 9)+7)
```
