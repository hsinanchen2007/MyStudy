```
class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        a = 0
        b = 0
        for i in range(len(s)):
            if s[i] == "R":
                a += 1
            else:
                a -= 1
            if a == 0:
                b += 1
        return b
```
