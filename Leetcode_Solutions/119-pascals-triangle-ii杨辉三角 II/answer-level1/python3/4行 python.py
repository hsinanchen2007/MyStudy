```python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        r = [1]
        for i in range(1, rowIndex + 1):
            r = [1] + [sum(r[j:j+2]) for j in range(i)]
        return r
```
- 跟一没差