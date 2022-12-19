```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        col0 = False
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                col0 = True
            for j in range(1,len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, len(matrix)):
            for j in range(1, len(matrix[0])):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if matrix[0][0] == 0:
            for i in range(1,len(matrix[0])):
                matrix[0][i] = 0
        if col0:
            for i in range(len(matrix)):
                matrix[i][0] = 0
```
