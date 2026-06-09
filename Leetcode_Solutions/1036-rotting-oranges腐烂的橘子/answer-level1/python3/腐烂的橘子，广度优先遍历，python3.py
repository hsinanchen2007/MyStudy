### 解题思路
所有的根节点同时开始广度优先遍历
遍历结束之后，如果已经不存在完好的橘子，就返回遍历轮数，否则返回-1
特殊情况：如果一开始就没有橘子，返回0

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        direction = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        troot = [[i, j] for i in range(len(grid)) for j in range(len(grid[0])) if grid[i][j] == 2]
        def bfs(root, times):
            if not root:
                return times-1
            next_root = []
            for ro in root:
                for dirt in direction:
                    if 0<=ro[0]+dirt[0]<=len(grid)-1 and 0<=ro[1]+dirt[1]<=len(grid[0])-1:
                        if grid[ro[0]+dirt[0]][ro[1]+dirt[1]] == 0 or grid[ro[0]+dirt[0]][ro[1]+dirt[1]] == 2:
                            continue
                        else:
                            grid[ro[0]+dirt[0]][ro[1]+dirt[1]] = 2
                            next_root.append([ro[0]+dirt[0], ro[1]+dirt[1]])
            return bfs(next_root, times+1)
        ans = bfs(troot, 0)
        flag = False
        for i in grid:
            for j in i:
                if j == 2:
                    flag = True
                if j == 1:
                    return -1
        if not flag: return 0
        return ans
            

                    
            
```