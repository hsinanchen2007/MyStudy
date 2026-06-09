```
class Solution(object):
    def findString(self, words, s):
        """
        :type words: List[str]
        :type s: str
        :rtype: int
        """

        return words.index(s) if s in words else -1
```
