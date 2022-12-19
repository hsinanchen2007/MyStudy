### 解题思路
用land保持初始陆地点，从陆地点往外扩散，若为海域则成功扩散，该轮成功扩散到的新点为下一轮的初始点，循环直至不存在新的扩散点。
成功扩散轮次即为所求值。

![TIM图片20200329124145.png](https://pic.leetcode-cn.com/bf95620e422fac2d0b96b2e590774e5993b72c5cab60665ecf4eda83ddf1e9ad-TIM%E5%9B%BE%E7%89%8720200329124145.png)


### 代码

```python
class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        N = len(grid)
        land = [(i, j) for i in range(N) for j in range(N) if grid[i][j]]
        
        if len(land) == 0 or len(land) == N*N:
            return -1
        
        def isvalid(a,b):
            return -1 < a < N and -1 < b < N
        
        length = -1
        while land:
            length += 1
            new_land = []
            for (x, y) in land:
                if isvalid(x-1,y) and grid[x-1][y] == 0:
                    grid[x-1][y] = 1
                    new_land.append((x-1,y))
                if isvalid(x+1,y) and grid[x+1][y] == 0:
                    grid[x+1][y] = 1
                    new_land.append((x+1,y))
                if isvalid(x,y-1) and grid[x][y-1] == 0:
                    grid[x][y-1] = 1
                    new_land.append((x,y-1))
                if isvalid(x,y+1) and grid[x][y+1] == 0:
                    grid[x][y+1] = 1
                    new_land.append((x,y+1))
            land = new_land
        return length
```