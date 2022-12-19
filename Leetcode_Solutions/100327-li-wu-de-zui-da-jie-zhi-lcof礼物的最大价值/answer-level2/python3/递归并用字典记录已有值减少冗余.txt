### 解题思路

![image.png](https://pic.leetcode-cn.com/00257dc7e474432bba7f345c20a74ee225ac8698289c124436350a59fc3f3cc0-image.png)

### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        if not grid:
            return
        m = len(grid)
        n = len(grid[0])
        mem = {}
        mem[(0, 0)] = grid[0][0]

        def core(i, j):
            if (i, j) in mem:
                return mem[(i, j)]
            else:
                mem[i, j] = 0
                if i == 0 and j > 0:
                    if (i, j - 1) not in mem:
                        mem[(i, j - 1)] = core(i, j - 1)
                    mem[(i, j)] = mem[(i, j - 1)] + grid[i][j]
                elif i > 0 and j == 0:
                    if (i - 1, j) not in mem:
                        mem[(i - 1, j)] = core(i - 1, j)
                    mem[(i, j)] = mem[(i - 1, j)] + grid[i][j]
                elif i > 0 and j > 0:
                    mem[(i, j)] = max(core(i, j - 1), core(i - 1, j)) + grid[i][j]
                return mem[(i, j)]
        return core(m - 1, n - 1)
```