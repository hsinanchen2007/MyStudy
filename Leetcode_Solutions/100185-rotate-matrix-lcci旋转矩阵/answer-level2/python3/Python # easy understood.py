### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        #   a[i][j]     →   a[j][N-1-i]
        #       ↑              ↓
        #   a[N-1-j][i] ←   a[N-1-i][N-1-j]
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return

        N = len(matrix)
        NF = math.ceil(N/2)
        for i in range(0, NF):
            for j in range(i, N-1-i):
                matrix[i][j], matrix[j][N-1-i], matrix[N-1-i][N-1-j], matrix[N-1-j][i] = matrix[N-1-j][i], matrix[i][j], matrix[j][N-1-i], matrix[N-1-i][N-1-j]
    
```