```
class Solution(object):
    def isSubsequence(self,s, t):
        """
        :type a: str
        :type b: str
        :rtype: bool
        """
        t = iter(t)
        return all(i in t for i in s)
```
