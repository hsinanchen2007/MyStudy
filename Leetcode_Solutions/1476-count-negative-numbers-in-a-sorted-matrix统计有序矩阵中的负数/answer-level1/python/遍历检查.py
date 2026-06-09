### 解题思路
只要查找每行的第一个负数，就可以知道后面的全部是负数，在while判断的时候先判断当前index小于列数，不然会有超出序列报错。

### 代码

```python
class Solution(object):
    def countNegatives(self, grid):
        #行数
        m = len(grid)
        #列数
        n = len(grid[0])
        count = 0
        for i in range(m):
            j = 0
            while j<n and grid[i][j] >= 0:
                j += 1
            count += (n - j)
        return count
```