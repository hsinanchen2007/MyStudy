### 解题思路
这道题我用的最简单的解法，思路非常清晰，开三个tmp来储存要迁移的元素就可以了。代码如下：

### 代码

```python3
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        M = len(grid)
        N = len(grid[0])
        for _ in range(k):                      ###共迁移k次
            tmp_1 = [i[:N-1] for i in grid]     ###创建tmp储存前N-1列数
            tmp_2 = [i[-1] for i in grid]       ###创建tmp储存最后一列数
            tmp_3 = grid[M-1][N-1]              ###创建tmp储存右下角那个数
            for i in range(M):
                for j in range(N-1):
                    grid[i][j+1] = tmp_1[i][j]  ###第一步迁移：将前N-1列的值赋给后N-1列
            for i in range(M-1):
                grid[i+1][0] = tmp_2[i]         ###第二步迁移：将最后一列的前M-1个值赋给第一列的后M-1个元素
            grid[0][0] = tmp_3                  ###第三步迁移：将右下角那个数的值赋给左上角那个元素
        return grid
```