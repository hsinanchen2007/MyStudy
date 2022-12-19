```
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int

        set
        """
        ss = set()
        for c in s:
            if c not in ss:
                ss.add(c)
            else:
                ss.remove(c)
        if len(ss) > 0:
            return len(s) - len(ss) + 1
        else:
            return len(s)
```
