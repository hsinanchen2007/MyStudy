```
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        left = 0
        right = x // 2 + 1
        while left < right:
            mid = (left+right+1)>>1
            square = mid**2
            if square > x:
                right = mid - 1
            else:
                left = mid
        
        return left
```
