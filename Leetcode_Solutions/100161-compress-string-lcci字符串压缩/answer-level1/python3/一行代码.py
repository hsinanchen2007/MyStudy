使用 `itertools`里的 `groupby`

```python
class Solution:
    def compressString(self, S: str) -> str:
        return min( S, "".join(k + str(len(list(v))) for k, v in itertools.groupby(S)), key=len)
```
