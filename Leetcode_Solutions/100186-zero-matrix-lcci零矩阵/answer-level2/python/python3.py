### 解题思路
额外空间O(1)

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        m = len(matrix)
        n = len(matrix[0])
        col,raw = False, False  #标注0，0位置是表示行还是列
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    matrix[i][0]=0
                    if i==0:
                        raw=True
                    matrix[0][j]=0
                    if j==0:
                        col=True
        
        for i in range(1,m):
            if matrix[i][0]==0:
                for j in range(1,n):
                    matrix[i][j]=0
        for j in range(1,n):
            if matrix[0][j]==0:
                for i in range(1,m):
                    matrix[i][j]=0
        
        if matrix[0][0]==0:
            if raw:
                for j in range(n):
                    matrix[0][j]=0
            if col:
                for i in range(m):
                    matrix[i][0]=0
        return matrix
        
        
        
        
        
        
        
        
        
        
```