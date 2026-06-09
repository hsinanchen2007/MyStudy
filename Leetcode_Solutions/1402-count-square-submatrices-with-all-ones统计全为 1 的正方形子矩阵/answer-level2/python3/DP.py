```
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        raw=len(matrix)
        coloum=len(matrix[0])
        Result=[[0 for _ in range(coloum)]for _ in range(raw)]        
        Result[0]=matrix[0]
        for s in range(raw):
            Result[s][0]=matrix[s][0]
        for i in range(1,raw):
            for j in range(1,coloum):
                if matrix[i][j] != 0:
                    Result[i][j]=min(Result[i-1][j-1],Result[i][j-1],\
                         Result[i-1][j]) + 1
        total=0
        for L in Result:
            total += sum(L)
        return total
```
