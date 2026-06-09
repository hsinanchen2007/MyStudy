### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        s=s.split()
        try:
            while True:
                s.remove(' ')
        except ValueError:
            s=s[::-1]
            return ' '.join(s)
```