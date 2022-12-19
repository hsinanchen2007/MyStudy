
```
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
                
        raw = len(matrix)
        col = len(matrix[0])
        #rem用来记录0的位置，比如rem = [[0,0]]代表第一行第一列是0
        rem = []
        for i in range(raw):
            for j in range(col):
                if matrix[i][j] == 0:
                    rem.append([i,j])
        
        #对rem中记录的位置对应的行和列全部置0，完成任务
        for i,j in rem:
            for m in range(col):
                matrix[i][m] = 0
            for n in range(raw):
                matrix[n][j] = 0
                       
        return matrix
                    
```
