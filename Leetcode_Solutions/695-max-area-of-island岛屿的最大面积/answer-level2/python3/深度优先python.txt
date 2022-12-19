### 解题思路
这题看上去要找到所有的岛屿比大小，岛屿的话就是连成一片的1。
所以写个递归让他能返回一整片岛屿的面积，并且把岛屿的1清零。
然后遍历每一个点，如果是1就递归算一下面积
把所有的面积的最大值return即可

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        islandArea = [0]#没有就输出0
        for row in range(len(grid)):
            for column in range(len(grid[0])):
                if (grid[row][column] == 1):
                    islandArea.append(self.countArea(grid,row,column))
        return max(islandArea)

    def countArea(self,grid,x,y):
        if x<0 or y < 0 or x >= len(grid) or y >= len(grid[0]):#出界了
            return 0
        if grid[x][y] == 1:
            grid[x][y] = 0 #防止被重复计算
            return 1 + self.countArea(grid,x+1,y) +\
                self.countArea(grid,x,y+1) +\
                self.countArea(grid,x,y-1) +\
                self.countArea(grid,x-1,y)
        if grid[x][y] == 0:
            return 0
```