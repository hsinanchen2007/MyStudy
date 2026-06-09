```python
from functools import reduce
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        return reduce(lambda a,_:[1,*map(int.__add__,a,a[1:]),1],range(rowIndex),[1])
```