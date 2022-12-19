### 解题思路
先遍历一遍矩阵，把等于0的元素的行和列存下来
再遍历一边矩阵，如果当前元素的行存在于x中或者列存在于y中，则置零

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        x = []
        y = []
        for m in range(len(matrix)):
            for n in range(len(matrix[0])):
                if matrix[m][n] == 0:
                    x.append(m)
                    y.append(n)
                    continue
        for m in range(len(matrix)):
            for n in range(len(matrix[0])):
                if m in x or n in y:
                    matrix[m][n] = 0
```