```python
class Solution:
    def titleToNumber(self, s: str) -> int:
        return sum((ord(c) - 64) * 26**i for i, c in enumerate(s[::-1]))
```