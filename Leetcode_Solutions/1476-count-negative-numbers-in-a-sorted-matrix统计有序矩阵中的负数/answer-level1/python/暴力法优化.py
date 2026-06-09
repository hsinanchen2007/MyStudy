### 解题思路
 当遇到每一行的第一个负数，直接计算出该行的负数个数（因为递减顺序排列）

### 代码

```python
class Solution(object):
    def countNegatives(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid[0])
        n = len(grid)
        count = 0
        for x in range(n):
            for y in range(m):
                if grid[x][y] < 0:
                    count += m - y
                    break
        return count
```