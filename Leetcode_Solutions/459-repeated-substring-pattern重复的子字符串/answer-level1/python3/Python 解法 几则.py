```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return (s + s)[1: -1].find(s) != -1

class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return (s + s)[1:-1].count(s) != 0
        

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s + s)[1: -1]

```