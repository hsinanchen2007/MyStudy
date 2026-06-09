```
class Solution:
    def titleToNumber(self, s: str) -> int:
        v = 0
        for i in s:
            v = v*26 + ord(i) - ord('A') + 1
        return v
```
