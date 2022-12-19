

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix[0])
        n = len(matrix)
        outX,outY = [],[]
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    outX.append(i)
                    outY.append(j)
        for i in range(len(outX)):
            for p in range(m):
                matrix[outX[i]][p] = 0
            for p in range(n):
                matrix[p][outY[i]] = 0


```