### 解题思路
将矩阵拆分重组成一维列表，直接判断target是否存在。

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        res = []
        for i in range(len(matrix)):
            res += matrix[i]
        return target in res
```