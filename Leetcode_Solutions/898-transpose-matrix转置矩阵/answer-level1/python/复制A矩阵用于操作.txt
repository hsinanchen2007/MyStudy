### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def transpose(self, A):
        B = copy.deepcopy(A)
        R, C = len(A),len(A[0])
        matrix = [None] * C
        for i in range(len(matrix)):
            matrix[i] = [0] * R
        for i in range(R):
            for j in range(C):
                matrix[j][i] = B[i][j]
        return matrix


```