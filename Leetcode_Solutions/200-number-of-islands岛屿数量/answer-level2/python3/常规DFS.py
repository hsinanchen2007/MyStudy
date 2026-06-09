### 解题思路

常规套路就是：
- 先做参数检查
- 初始化cnt=1
- 二维扫描全部cell
- 如果cell==1，cnt++，然后从这个cell开始DFS
- DFS里先判断cell坐标是否合法
- 如果cell==1，将cell内容改为cnt，然后上下左右4个方向再DFS，直到退出
- 如此这样扫描完全部cell，输出cnt-1即是最终结果
- 上面做法的好处，是用2,3,...标记了每一个不同的岛屿，虽然本题不需要，但是仍然有价值

### 代码

```python3
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # - sanity check
        if (not grid) or (len(grid[0])==0): 
            return 0

        # - get row and col of grid
        n_row, n_col = len(grid), len(grid[0])

        # - (dx,dy) if go up/right/down/left
        dirs = [(0,-1),(1,0),(0,1),(-1,0)]

        # - later will cnt-1 to get island count
        cnt = 1

        # - dfs
        def dfs(row,col):
            # - check if row and col are valid
            if (row<0) or (col<0) or (row>=n_row) or (col>=n_col):
                return

            # - if current cell is island, continue dfs
            if grid[row][col] == '1':
                # - replace '1' with new char
                grid[row][col] = '%s' % cnt

                # - try 4 directions
                for dx,dy in dirs:
                    dfs(row+dx, col+dy)
        
        # - traverse all cells
        for row in range(n_row):
            for col in range(n_col):
                if grid[row][col] == '1':
                    cnt += 1
                    dfs(row,col)
        
        # - return island count
        return cnt-1
```