### 解题思路
先记录0出现的位置，然后把对应位置的行列改为0
### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        visitedi=set()  #记录0的位置
        for j in range(len(matrix[0])):
            for i in range(len(matrix)):
                if matrix[i][j]==0:
                    visitedi.add((i,j))
        for i,j in visitedi:
            for k in range(len(matrix[0])):
                matrix[i][k]=0
            for t in range(len(matrix)):
                matrix[t][j]=0
        

                
        
                    

```