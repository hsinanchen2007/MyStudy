用python切片，直接一个循环下去
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n_len = len(needle)
        if n_len == 0:
            return 0
        if n_len > len(haystack):
            return -1
        for i in range(len(haystack) - n_len + 1):
            if haystack[i:i+n_len] == needle:
                return i
        return -1
```
