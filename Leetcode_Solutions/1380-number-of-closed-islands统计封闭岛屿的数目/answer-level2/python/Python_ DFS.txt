### 解题思路
此题于岛啊船啊等题类似：核心在于找到岛之后用深度优先搜索把整个岛替换成湖。这题要注意的是只有当岛不在 matrix boundary 上的时候才increase count。用一个 flag 标注岛是否靠边。在 Python 函数里面，如果要更新variable，需要用`self.xxx`。也可以直接用list，比如 `flag[0]`。

### 代码

```python
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        if not grid: return 0
        m, n = len(grid), len(grid[0])        
        def dfs(i, j):
            if 0 <= i < m and 0 <= j < n and grid[i][j] == 0:
                grid[i][j] = 1
                if i in [0, m-1] or j in [0, n-1]: self.flag = True
                for (x, y) in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                    dfs(x, y)        
        cnt = 0        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    self.flag = False
                    dfs(i, j)
                    if not self.flag: 
                        cnt +=1        
        return cnt 
```