### 解题思路
1. 先整个大网格，用0填充
2. 从0，0开始向下，向右遍历表格，当表格的数加一起小于k+1的时候，并且，当前表格的上一个或者左一个表格为1，则把当前表格也置为1。这样是为了能够让这个表格通过别的表格到达当前表格。
3. 结束后计算所有表格中1的个数。

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        reach_grid = [[0]*n for _ in range(m)]
        def add_num(num):
            return num%10 + num//10
        reach_grid[0][0] = 1
        for i in range(m):
            for j in range(n):
                if add_num(i) + add_num(j) < k+1 and ((j and reach_grid[i][j-1]) or (i and reach_grid[i-1][j])):
                    reach_grid[i][j] = 1
        return sum([sum(line) for line in reach_grid])
```