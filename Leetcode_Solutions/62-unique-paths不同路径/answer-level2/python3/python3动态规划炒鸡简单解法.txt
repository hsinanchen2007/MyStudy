### 解题思路
拆解为小问题，由于只能向右或者向下走所以
1. 对于每一个格子来说，到达它的只会是上面的格子以及左边的格子。
2. 对于每一个格子来说，到达它的路径数会是 上面的格子的路径数+左边的格子的路径数。
3. 定义一个可以保存每一个各自路径数的二维数组。
4. M * N的格子，M是列，N是行，我们从第一行开始依次计算，左右后面的格子都会依赖前面的计算结果。

### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        record = [[0] * m for i in range(n)]
        for r in range(n):
            for c in range(m):
                if r == 0 and c == 0:
                    record[r][c] = 1
                else:
                    top = record[r-1][c]  if r >0 else 0
                    left = record[r][c-1]  if c >0 else 0
                    record[r][c] = top + left
        return record[n-1][m-1]
```