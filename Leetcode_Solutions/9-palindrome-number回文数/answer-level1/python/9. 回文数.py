```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # # 1
        # return str(x) == str(x)[::-1]
        
        # 2
        if x < 0:
            return False
        num, rev = x, 0
        while num:
            rev = rev * 10 + num % 10
            num /= 10
        return rev == x
```
