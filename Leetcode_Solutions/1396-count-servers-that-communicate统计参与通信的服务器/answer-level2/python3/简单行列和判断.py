-   利用当前行和列的和进行判断

```
满足下面条件，当前元素无法进行通信：
dp[x][y] == 1
row_sum[x] == 1
col_sum[y] == 1

将无法通信的节点数量加一
```



```python
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        row_sum = [sum(r) for r in grid]
        col_sum = [sum([grid[i][j] for i in range(row)]) for j in range(col)]

        appear_once = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] and row_sum[i] == 1 and col_sum[j] == 1:
                    appear_once += 1
        return sum(row_sum) - appear_once
```