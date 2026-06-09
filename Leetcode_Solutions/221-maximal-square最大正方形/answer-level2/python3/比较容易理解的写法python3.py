思路都是一样的，动态规划
```
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                    matrix[i][j] = int(matrix[i][j])
                    if i!=0 and j!=0 and matrix[i][j]!=0:
                        matrix[i][j] = 1+min(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1])
                    ans = max(ans,matrix[i][j])
        
        return ans*ans
```
