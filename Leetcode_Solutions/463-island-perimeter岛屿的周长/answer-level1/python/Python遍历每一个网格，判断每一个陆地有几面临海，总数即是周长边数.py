思路：遍历每一个网格，判断每一个陆地有几面临海，总数即是周长边数
![image.png](https://pic.leetcode-cn.com/2ff4b74a8fa3c555f8fe01717c6e3534e5201610c3c06a131f9ed94f9b916ac6-image.png)

```
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ret = 0
        for x in xrange(0,len(grid)):
            for y in xrange(0,len(grid[x])):
                if grid[x][y] == 1:
                    #判断这块陆地几面临海
                    ret += self.get_seas(grid,x,y)
        return ret

    #判断一个陆地有几个边临海
    def get_seas(self,grid,x,y):
        seas = 0
        if self.is_left_sea(grid,x,y):
            seas += 1
        if self.is_right_sea(grid,x,y):
            seas += 1
        if self.is_up_sea(grid,x,y):
            seas += 1
        if self.is_down_sea(grid,x,y):
            seas += 1
        return seas

    #判断左边是否临海
    def is_left_sea(self,grid,x,y):
        if y == 0:
            return True
        return grid[x][y-1] == 0

    def is_right_sea(self,grid,x,y):
        if y == len(grid[x])-1:
            return True
        return grid[x][y+1] == 0

    def is_up_sea(self,grid,x,y):
        if x == 0:
            return True
        return grid[x-1][y] == 0

    def is_down_sea(self,grid,x,y):
        if x == len(grid)-1:
            return True
        return grid[x+1][y] == 0


```
