
```python []
class Solution:
    def compressString(self, S: str) -> str:
        s = ''.join(c + str(len([*v])) for c, v in itertools.groupby(S))
        return len(s) < len(S) and s or S
```