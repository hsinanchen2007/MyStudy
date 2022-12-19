```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            bb = haystack.index(needle)
            return(bb)
        except ValueError:
            return(-1)
```
