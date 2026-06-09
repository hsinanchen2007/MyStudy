```python
from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1] * (rowIndex+1)
        for i in range(1,rowIndex+1):
            pre = 1
            for j in range(1, i):
                tmp = res[j]
                res[j] += pre
                pre = tmp
        return res
```