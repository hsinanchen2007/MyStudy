构造一个矩阵，使每个元素为该元素到第零个元素构成区域的和

```
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        row = len(matrix)
        if row == 0:
            return
        col = len(matrix[0])
        for i in range(row):
            for j in range(col):
                a = matrix[i][j-1] if j>0 else 0
                b = matrix[i-1][j] if i>0 else 0
                c = matrix [i-1][j-1] if j>0 and i >0  else 0
                matrix[i][j]+= a+b-c
        self.data = matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if self.data == None:
            return None
        a = self.data[row1-1][col2] if row1>0 else 0
        b = self.data[row2][col1-1] if col1>0 else 0
        c = self.data[row1-1][col1-1] if row1 >0 and col1 >0 else 0
        return self.data[row2][col2]-a-b+c

```
