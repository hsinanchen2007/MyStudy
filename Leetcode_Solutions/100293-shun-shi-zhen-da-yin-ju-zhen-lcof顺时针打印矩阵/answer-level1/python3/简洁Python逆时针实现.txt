### 解题思路
每次pop第一行，然后逆时针旋转矩阵，重复操作直至为空

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        res = []
        while matrix:
            res.extend(matrix.pop(0))
            new_mat = []
            for x in zip(*matrix):
                new_mat.append(x)
            matrix = new_mat[::-1]
        return res
```