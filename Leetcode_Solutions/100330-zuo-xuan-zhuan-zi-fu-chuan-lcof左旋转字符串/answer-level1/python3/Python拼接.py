### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        l = len(s)
        if l == 0 or n == 0:
            return l
        return s[n%l:] + s[:n%l]
```