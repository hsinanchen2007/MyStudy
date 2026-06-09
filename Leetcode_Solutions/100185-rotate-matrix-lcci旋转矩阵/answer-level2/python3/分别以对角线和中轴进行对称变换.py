### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix:return
        row,col = len(matrix),len(matrix[0])
        for i in range(row):
            for j in range(i,col):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
        for i in range(row):
            for j in range(col//2):
                matrix[i][j],matrix[i][col-j-1] = matrix[i][col-j-1],matrix[i][j]
```