我们只需要递推出数列的第一项是多少，不需要用数列记录每一项的值。

```
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1: return 1

        x1, x2 = 1, 2
        while n > 2:
            x1, x2 = x2, x1+x2
            n = n-1
        return x2
```
