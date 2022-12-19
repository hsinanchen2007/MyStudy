### 解题思路
这道题和求岛屿周长的思路一样，只是本题是立体的，加上上下两个面就行。
对于每个格子，判断上下左右的情况：
1.如果旁边是界外就直接相加；
2.如果旁边有相邻的方块，比较一下高低：比旁边格子低就不用加，比旁边格子高就加上差值。

注意：方块的底部也算是表面积。

本题的题目甚是难懂，感谢评论区的大佬解惑！！

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        m, n = len(grid), len(grid[0])

        self.sumArea=0

        def getArea(i, j):
            self.sumArea+=2  #方块的上下两个面积
            for x,y in [(1,0),(-1,0),(0,1),(0,-1)]:
                new_i=i+x
                new_j=j+y
                if new_i>=m or new_i<0 or new_j>=n or new_j<0:
                    self.sumArea+=grid[i][j]   #旁边是边界
                elif grid[i][j]>grid[new_i][new_j]:  #旁边不是边界
                    self.sumArea+=grid[i][j]-grid[new_i][new_j]
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]>0:
                    getArea(i, j)
        return self.sumArea
```