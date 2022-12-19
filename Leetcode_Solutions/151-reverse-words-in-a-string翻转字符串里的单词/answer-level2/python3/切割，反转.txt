

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:

        return " ".join(reversed(s.split()))
```