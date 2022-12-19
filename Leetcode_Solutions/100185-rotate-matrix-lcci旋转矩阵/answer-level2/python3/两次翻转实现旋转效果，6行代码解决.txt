### 解题思路
先沿着水平中轴线垂直旋转，再沿着左上右下对角线旋转。用Python实现不到十行……

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row_count = len(matrix)
        # 沿着水平中轴线垂直旋转
        for row_index in range(row_count // 2):
            matrix[row_index], matrix[row_count - 1 - row_index] = matrix[row_count - 1 - row_index], matrix[row_index]
        # 沿着左上右下对角线旋转
        for row_index in range(row_count):
            for col_index in range(row_index):
                matrix[row_index][col_index], matrix[col_index][row_index] = matrix[col_index][row_index], matrix[row_index][col_index]
```