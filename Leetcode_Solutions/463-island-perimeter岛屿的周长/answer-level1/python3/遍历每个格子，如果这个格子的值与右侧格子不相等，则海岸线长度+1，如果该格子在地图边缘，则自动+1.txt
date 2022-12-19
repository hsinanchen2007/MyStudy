```
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
#遍历每个格子，如果这个格子的值与右侧格子不相等，则海岸线长度+1，如果该格子在地图边缘，则自动+1     
        island = 0
        for i in range(len(grid[0])-1):
            for j in range(len(grid)):
                if grid[j][i] != grid[j][i+1]:
                    island += 1
            #计算每一行有多少格子的值与右侧不一样，得到地图内部纵向海岸线长度
        for i in [0, len(grid[0])-1]:
            for j in range(len(grid)):
                if grid[j][i] == 1:
                    island += 1
            #计算有多少值为1的格子是挨着地图左右两边的，得到地图左右两边纵向海岸线长度
        grid = list(zip(*grid))  #将整个地图转置，把上面两步再做一次，得到所有横向海岸线长度
        for i in range(len(grid[0])-1):
            for j in range(len(grid)):
                if grid[j][i] != grid[j][i+1]:
                    island += 1
        for i in [0, len(grid[0])-1]:
            for j in range(len(grid)):
                if grid[j][i] == 1:
                    island += 1
        return island




```
