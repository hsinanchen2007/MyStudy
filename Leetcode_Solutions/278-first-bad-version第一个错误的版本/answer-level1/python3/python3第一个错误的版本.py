```
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        if isBadVersion(1):
            return 1
        right = n
        left = 1
        while right-left>1:
            h = (right+left)//2
            if isBadVersion(h):
                right = h
            else:
                left = h
        return right
```
