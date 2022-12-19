![image.png](https://pic.leetcode-cn.com/33bb30dd03cfb55df99b81cc4fdd5493bf195894daf7496946a0c48c5b3f075e-image.png)

遍历岛中的每个位置
如果位置为0，则直接查看下一个位置
直到发现有位置为1的，从该位置去查看它的上下左右，然后将面积进行加和

最后选取面积最大的数值进行返回

### 代码

```python
class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        m,n = len(grid), len(grid[0])
        ans = 0
        def dfs(grid, x,y):
            if 0<=x<m and 0<=y<n and grid[x][y]==1:
                grid[x][y] = 0
                return 1+dfs(grid, x+1,y)+dfs(grid,x-1,y)+dfs(grid, x,y-1)+dfs(grid, x,y+1)
            return 0
        


        for i in range(m):
            for j in range(n):
                ans = max(ans, dfs(grid,i,j))
        return ans
```