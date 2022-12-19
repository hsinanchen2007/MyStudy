### 解题思路
遍历，并将遍历过的1转变为0，防止重复遍历。

### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        nr = len(grid)
        nc = len(grid[0])
        ans = 0
        for i, h in enumerate(grid):
            for j, l in enumerate(h):
                if grid[i][j]:
                    cur = 1
                    grid[i][j] = 0
                    stack = [(i, j)]
                    while stack:
                        cur_ip, cur_jp = stack.pop()
                        for di, dj in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                            cur_i = cur_ip + di; cur_j = cur_jp + dj
                            if cur_i >= 0 and cur_i <= nr-1 and cur_j >= 0 and cur_j <= nc-1 and grid[cur_i][cur_j]:
                                cur += 1; grid[cur_i][cur_j] = 0
                                stack.append((cur_i, cur_j))
                    ans = cur if cur > ans else ans
        return ans


    
```