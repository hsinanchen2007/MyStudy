```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        if not haystack:
            return -1
        return len(haystack.split(needle)[0]) if needle in haystack else -1
```