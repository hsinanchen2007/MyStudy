
### 代码

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()  # 去除首尾的括号
        start = len(s) - 1
        end = len(s)
        res = ''
        while start > 0:
            if s[start] == ' ':
                res += s[start + 1: end] + ' '
                while s[start] == ' ':
                    start -= 1
                end = start + 1
            start -= 1
        return res + s[:end]
```