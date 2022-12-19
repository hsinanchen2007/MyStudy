### 解题思路
此处撰写解题思路

### 代码

```python3
import numpy as np
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        matnums = []
        for i in mat:
            matnums.append(sum(i))
        arr = np.array(matnums)
        nums = np.argsort(arr,kind='mergsort')

        return nums[:k]
```