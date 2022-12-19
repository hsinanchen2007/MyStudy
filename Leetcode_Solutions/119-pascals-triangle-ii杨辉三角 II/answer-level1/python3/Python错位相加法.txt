```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        a = [1]
        for _ in range(rowIndex):
            b = a[:]
            a, b = [0]+a, b+[0]
            a = [a[i]+b[i] for i in range(len(a))]
        return a
```
