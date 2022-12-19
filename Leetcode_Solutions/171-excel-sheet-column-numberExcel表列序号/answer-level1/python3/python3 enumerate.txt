曾经因为不知道enumerate可以返回index和value而面试没有写出Pythonic的解，此处记录一下。

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        return sum((ord(c) - 64) * 26 ** i for i, c in enumerate(s[::-1]))
```
