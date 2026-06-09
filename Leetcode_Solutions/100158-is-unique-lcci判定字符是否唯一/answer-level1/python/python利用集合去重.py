```
class Solution(object):
    def isUnique(self, astr):
        """
        :type astr: str
        :rtype: bool
        """
        return sorted(list(astr)) == sorted(list(set(astr)))
```
