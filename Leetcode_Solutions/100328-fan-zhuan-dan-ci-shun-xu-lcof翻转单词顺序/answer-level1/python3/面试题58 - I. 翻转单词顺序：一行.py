

```python []
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(filter(bool, s.split()[:: -1]))
```