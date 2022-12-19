```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.split()[::-1])
```
- python 的 split 中的分隔符，默认为所有的空字符，包括空格、换行(\n)、制表符(\t)等