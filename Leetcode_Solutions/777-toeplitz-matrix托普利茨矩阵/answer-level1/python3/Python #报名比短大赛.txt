### 解题思路

上下两行比头尾两端

### 代码

```python3
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        return all(a[:-1] == b[1:] for a, b in zip(matrix[:-1], matrix[1:]))
```