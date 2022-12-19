### 解题思路
深度优先搜索
- 首先，遍历二维网格中的每一个网格；
- 如果当前网格是水域，则跳过；
- 如果当前网格是陆地，则统计当前网格所能连通的陆地数量，即网格数量；
  - 统计方法也很简单，就是将当前网格及其上下左右四周网格所连通的陆地数量加起来即可；
  - 同时，在统计的过程中，对于已经访问过的网格要打上标记，避免重复访问和死循环；
  - 上述方案即是深度优先搜索的思路，当某个网格的深搜完成之后，只需要判断当前网格连通陆地的数量是否大于0即可，若大于0，则说明该网格连接着一座岛屿，则岛屿数量加1；否则，继续遍历下一个网格；

另外，该方法还适用于统计岛屿的最大面积，这样的题目，只需要找出每一次遍历结果中的最大值即可。

### 代码

```python3
class Solution:

    def find(self, rx, cy):
        # top
        if self.grid[rx][cy] != '1':
            return 0
        
        flag = 1
        self.grid[rx][cy] = '-1'   # 表示已访问过

        if rx-1 >= 0 and self.grid[rx-1][cy] == '1':    # 未访问过, 且是陆地
            flag += self.find(rx-1, cy)

        # bottom
        if rx+1 < self.rows and self.grid[rx+1][cy] == '1':
            flag += self.find(rx+1, cy)

        # left
        if cy-1 >= 0 and self.grid[rx][cy-1] == '1':
            flag += self.find(rx, cy-1)

        
        if cy+1 < self.cols and self.grid[rx][cy+1] == '1':
            flag += self.find(rx, cy+1)
        
        return flag
        

    def numIslands(self, grid: List[List[str]]) -> int:
        self.rows = len(grid)
        if self.rows < 1:
            return 0
        self.cols = len(grid[0])
        self.grid = grid

        rst = 0
        for i in range(self.rows):
            for j in range(self.cols):
                flag = self.find(i, j)
                if flag > 0:
                    rst += 1
        
        return rst


```