
```
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        temp_sum = sum([sum(i) for i in grid])
        n = len(grid)
        if temp_sum == 0 or temp_sum == n*n:
            return -1
        
        dis_matrix = [[100] * (n+2) for _ in range(n+2)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    dis_matrix[i+1][j+1] = 0
                else:
                    dis_matrix[i+1][j+1] = min(dis_matrix[i][j+1] + 1,dis_matrix[i+1][j] + 1)
        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                dis_matrix[i+1][j+1] = min(dis_matrix[i+1][j+1],dis_matrix[i+2][j+1]+1,dis_matrix[i+1][j+2]+1)

        return(max([max(i[1:-1]) for i in dis_matrix[1:-1]]))
```
