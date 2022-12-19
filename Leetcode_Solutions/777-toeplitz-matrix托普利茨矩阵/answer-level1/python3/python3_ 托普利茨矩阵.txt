```python
def isToeplitzMatrix(matrix):
    m, n = len(matrix), len(matrix[0])
    for i in range(m - 2, -1, -1):
        """
        每两行进行比较即可. 例如矩阵:
        [
            [1,2,3,4],
            [5,1,2,3],
            [9,5,1,2]
        ]
        先比较[5,1,2,3], [9,5,1,2]是否符合要求,
        然后再比较[1,2,3,4],[5,1,2,3]即可.
        """
        for j in range(0, n - 1):
            if matrix[i][j] != matrix[i + 1][j + 1]:
                return False
    return True

matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
print(isToeplitzMatrix(matrix))
```