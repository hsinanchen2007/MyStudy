```
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if not s:
            return True
        foo = 0
        for item in t:
            if s[foo] == item:
                foo+=1
            if foo ==len(s):
                return True

        return False
```
