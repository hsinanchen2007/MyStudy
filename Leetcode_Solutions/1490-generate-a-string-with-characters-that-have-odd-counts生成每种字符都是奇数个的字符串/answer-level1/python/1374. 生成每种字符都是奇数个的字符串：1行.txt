

```python []
class Solution:
    def generateTheString(self, n: int) -> str:
        return n % 2 and 'a' * n or 'a' + 'b' * (n - 1)
```