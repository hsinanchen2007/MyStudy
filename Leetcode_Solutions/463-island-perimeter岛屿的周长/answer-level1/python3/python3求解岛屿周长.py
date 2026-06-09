依次遍历网格中的每个元素，每个元素查找其周围是否有水（元素为0），是则周长加一。最终返回周长值。
```
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        peri=0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]==1:
                    if i-1<0 or grid[i-1][j]==0:
                        peri+=1
                    if j+1==len(grid[0]) or grid[i][j+1]==0:
                        peri+=1
                    if i+1==len(grid) or grid[i+1][j]==0:
                        peri+=1
                    if j-1<0 or grid[i][j-1]==0:
                        peri+=1
        return peri
```
