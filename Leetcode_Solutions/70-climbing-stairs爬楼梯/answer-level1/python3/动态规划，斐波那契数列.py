```
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<=2:
            return n
        p2 = 1
        p1 = 2
        for i in range(2, n):
            p2, p1 = p1, p1 + p2
        return p1
```
