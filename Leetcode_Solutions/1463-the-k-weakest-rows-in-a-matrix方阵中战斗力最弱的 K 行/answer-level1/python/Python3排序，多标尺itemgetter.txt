### 解题思路
利用元组列表保存两个标尺信息，然后利用`itemgetter(0, 1)`对这两个标尺进行排序

### 代码

```python3
from operator import itemgetter

class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        res = []
        for i in range(len(mat)):
            res.append((sum(mat[i]), i))
        sorted_res = sorted(res, key=itemgetter(0, 1))
        return [index for _, index in sorted_res[: k]]
```