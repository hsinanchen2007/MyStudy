```python
class Solution(object):
    def rotate(self, matrix):
        N = len(matrix)
        for i in range(N//2):
            for j in range(i,N-i-1):
                tmp1 = matrix[i][j]
                for k in range(4):
                    i_new, j_new = j, N-i-1
                    tmp2 = matrix[i_new][j_new]
                    matrix[i_new][j_new] = tmp1
                    tmp1 = tmp2
                    i, j = i_new, j_new
```
