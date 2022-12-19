比较笨的方法,找到索引对应规律, matrix[row][col]对应的旋转之后的索引是matrix[col][n - 1 - row]
```

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        import copy
        n = len(matrix)
        new_matrix = copy.deepcopy(matrix)
        for i in range(n * n):
            row = i // n
            col = i % n
            matrix[col][n - 1 - row] = new_matrix[row][col]

```
