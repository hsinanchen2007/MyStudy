假设该N*N的矩阵宽度为width, 将矩阵分为四个象限, 第一象限中某点位置为(row,col), 那么旋转时四象限中对应的位置分别：
    matrix[row][col] -> matrix[col][width-row]
    matrix[col][width-row] -> matrix[width-row][width-col], 
    matrix[width-row][width-col] -> matrix[width -col][row], 
    matrix[width-col][row] -> matrix[row][col]

```python []
class Solution:
    def rotate(self, matrix: [[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        width = len(matrix)
        center = width//2
        width -= 1
        if width % 2 == 0:
            for row in range(center):
                for col in range(center+1):
                    self.rotate_demo(matrix, row, col, width)
        else:
            for row in range(center):
                for col in range(center):
                    self.rotate_demo(matrix, row, col, width)

    def rotate_demo(self, matrix, row, col, width):
        matrix[col][width-row], matrix[width-row][width-col], matrix[width -
                                                                     col][row], matrix[row][col] = matrix[row][col], matrix[col][width-row], matrix[width-row][width-col], matrix[width-col][row]
```

