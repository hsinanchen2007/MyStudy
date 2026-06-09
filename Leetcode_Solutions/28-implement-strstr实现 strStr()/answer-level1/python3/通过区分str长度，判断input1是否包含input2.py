```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lenNeed = len(needle)
        if len(needle) == 0:
            return 0
        if len(needle)>len(haystack):
            return -1
        i = 0
        while i<=(len(haystack)-len(needle)):
            if haystack[i:i+lenNeed]==needle:
                return i
            else:
                i += 1
        return -1
```