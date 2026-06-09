### 解题思路
右上角开始判断
1. 比0大，下移一行
2. 比0小，计数  += 行数 - 当前行 - 1

### 代码

```python
class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        negative_num = 0
        m = len(grid)
        if m == 0:
            return negative_num
        n = len(grid[0])
        cur_row = 0
        cur_col = n - 1
        while cur_row < m and cur_col >= 0:
            if grid[cur_row][cur_col] >= 0:
                cur_row = cur_row + 1
            else:
                negative_num = negative_num + m - cur_row
                cur_col = cur_col - 1
        return negative_num

```