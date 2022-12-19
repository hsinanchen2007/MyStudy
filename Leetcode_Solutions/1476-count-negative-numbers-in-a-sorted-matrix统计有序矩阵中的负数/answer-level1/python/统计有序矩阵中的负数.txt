### 解题思路
遇到负数则该行和该列之后的列都不用考虑

### 代码

```python
class Solution(object):
    def countNegatives(self, grid):
        R = len(grid)
        Col = len(grid[0])
        C = Col
        i = 0
        j = 0
        count = 0
        while i < R and j < C:
            if grid[i][j] >= 0:
                count += 1     #记所有非负数的值
                j += 1
                if j == C:
                    i += 1
                    j = 0
            else:            #遇到负数则该行停止遍历，接下来的遍历中之后的列也不用考虑
                C = j
                i += 1
                j = 0
        return R * Col - count 
```