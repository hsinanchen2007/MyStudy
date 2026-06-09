```
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = 0
        h = x
        while l<h:
            m = (l+h+1)/2
            m2 = m*m
            if m2 == x:
                return m
            elif m2 < x:
                l = m
            else:
                h = m-1
        return l
```
