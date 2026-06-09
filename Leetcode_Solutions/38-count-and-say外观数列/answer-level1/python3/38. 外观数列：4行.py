```python []
class Solution:
    def countAndSay(self, n: int) -> str:
        a = '1'
        for _ in range(n - 1):
            a = ''.join(str(len([*s])) + c for c, s in itertools.groupby(a))
        return a
```
