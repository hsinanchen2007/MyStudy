```
class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0: return 1
        if n == 1: return 10
        return self.countNumbersWithUniqueDigits(n - 1) + (self.countNumbersWithUniqueDigits(n - 1) - self.countNumbersWithUniqueDigits(n - 2)) * (11 - n)
```
