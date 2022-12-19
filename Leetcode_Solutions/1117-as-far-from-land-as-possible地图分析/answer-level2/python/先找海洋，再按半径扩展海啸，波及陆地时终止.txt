### 解题思路
先找海洋，再按半径扩展海啸，波及陆地时终止

### 代码

```python3
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n = len(grid)
        acc = -1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    flag = False
                    for step in range(1,2*n-1):
                        for di in range(step + 1):
                            dj = step - di
                            for symbol_i,symbol_j in ((1,1),(1,-1),(-1,1),(-1,-1)):
                                i_new = i + di * symbol_i
                                j_new = j + dj * symbol_j
                                if 0 <= i_new < n and 0 <= j_new < n:
                                    if grid[i_new][j_new] == 1:
                                        acc = max(acc,step)
                                        flag = True
                                        break
                            if flag:
                                break
                        if flag:
                            break
        return acc
```