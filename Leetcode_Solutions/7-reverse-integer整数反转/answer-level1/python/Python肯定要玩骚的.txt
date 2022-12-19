```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        ans = int(str(abs(x))[::-1]) * (x/abs(x))
        return ans if -2**31<=ans<=2**31-1 else 0
```
