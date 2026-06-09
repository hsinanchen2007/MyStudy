class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0 

        res=0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])): 
                matrix[i][j]=int(matrix[i][j])
                if i==0 or j==0:
                    res=max(res,matrix[i][j])
                    continue
                    
                if matrix[i][j]==0:continue
            
                matrix[i][j]=min(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1])+1               
                res=max(res,matrix[i][j])

        return res**2