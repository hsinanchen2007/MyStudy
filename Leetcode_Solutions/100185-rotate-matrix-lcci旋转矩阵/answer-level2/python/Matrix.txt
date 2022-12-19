### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        newmatrix=[[0]*n for _ in range(n)]
#print(newmatrix)
        for i in range(n):
              for j in range(n):
                  newmatrix[j][n-i-1]=matrix[i][j]
        matrix[:]=newmatrix
```