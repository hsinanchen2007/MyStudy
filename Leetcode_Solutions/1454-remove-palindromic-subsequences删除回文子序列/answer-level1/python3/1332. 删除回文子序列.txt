1行
```python []
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return s == s[:: -1] and 1 or 2 if s else 0
```