### 解题思路

二分查找剪枝筛选，一般来说比O(N)法快

### 代码

```python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        p = len(matrix[0])
        for mat in matrix:
            if mat[-1] < target:
                continue
            if mat[0] > target:
                return False
            m = bisect.bisect(mat, target, hi = p)
            if mat[m - 1] == target:
                return True
            p = m
        return False
```