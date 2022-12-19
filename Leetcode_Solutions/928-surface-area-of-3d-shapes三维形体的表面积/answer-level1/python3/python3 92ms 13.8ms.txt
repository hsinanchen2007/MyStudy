执行用时 :92 ms, 在所有 Python3 提交中击败了89.66%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.77%的用户

先把周围的特殊情况解决了，然后依次从横向、纵向去查看新增的面积，最后加在一起，如果没有放正方体，这个格子没有贡献表面积，一旦放置盒子，无论多少个，都只会贡献上下两个表面积
```
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        area = 0
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if i==0:
                    area += grid[i][j]
                if i==n-1:
                    area += grid[i][j]
                if i:
                    area += abs(grid[i][j] - grid[i-1][j])
                    
                if j==0:
                    area += grid[i][j]
                if j==n-1:
                    area += grid[i][j]
                if j:
                    area += abs(grid[i][j] - grid[i][j-1])
                if grid[i][j]:
                    area += 2
        return area
```
