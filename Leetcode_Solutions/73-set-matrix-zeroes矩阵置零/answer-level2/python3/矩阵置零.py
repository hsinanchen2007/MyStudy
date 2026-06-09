时间复杂度：O(m*n)
空间复杂度：O(m+n)
```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        temp = []
        for i in range(len(matrix)+len(matrix[0])):
            temp.append(-1)
            
        m = len(matrix)
        n = len(matrix[0])
        
        for j in range(n):
            for i in range(m):
                if matrix[i][j] == 0:
                    temp[i] = 0
                    temp[m+j] = 0
        
        for i in range(m):
            for j in range(n):
                if temp[i] == 0:
                    matrix[i][j] = 0
        
        for i in range(n):
            for j in range(m):
                if temp[m+i] == 0:
                    matrix[j][i] = 0
```