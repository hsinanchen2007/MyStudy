暴力法求解，遍历整张图，遇到岛屿的位置（数值1），计算该点的四周岛屿点的数量（求1上下左右四个位置中1的数量count），则该点贡献的周长为4-count。
```
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        def helper(grid,i,j):
            count = 0
            for x,y in [(1,0),(-1,0),(0,1),(0,-1)]:
                tmp_i,tmp_j = i+x,j+y
                if 0<=tmp_i<=len(grid)-1 and 0<=tmp_j<=len(grid[0])-1 and grid[tmp_i][tmp_j] == 1:
                    count+=1
            return count
        
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]== 1:
                    count = helper(grid,i,j)
                    res += 4-count
        return res
```
