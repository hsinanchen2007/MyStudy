### 解题思路
观察到旋转这个矩阵可以分为两步来做，第一步对该矩阵进行转置，即令matrix[i][j]=matrix[j][i],第二步则是将第0列与最后一列互换，第1列与倒数第二列互换······新手轻喷

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n=len(matrix)
        matrix1=copy.deepcopy(matrix)
        for i in range(n):
            for j in range(n):
                matrix1[j][i]=matrix[i][j]
        for i in range(n):
            for j in range(n):
                matrix[i][j]=matrix1[i][n-j-1]
        return matrix
        """
        Do not return anything, modify matrix in-place instead.
        """
```