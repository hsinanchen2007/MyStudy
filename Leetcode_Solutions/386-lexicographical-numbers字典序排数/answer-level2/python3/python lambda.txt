```python []
class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        lst = list(range(1, n+1))
        lst.sort(key=str)
        return lst
```
嗯呐~