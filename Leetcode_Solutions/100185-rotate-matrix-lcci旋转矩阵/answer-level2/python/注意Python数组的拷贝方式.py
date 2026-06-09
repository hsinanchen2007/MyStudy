### 解题思路
注意 Python 的数组拷贝方式。
此类题要学会推导出坐标关系。

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        matrix_new = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                matrix_new[j][n-1-i] = matrix[i][j]
                
        matrix[:] = matrix_new
        
            
```