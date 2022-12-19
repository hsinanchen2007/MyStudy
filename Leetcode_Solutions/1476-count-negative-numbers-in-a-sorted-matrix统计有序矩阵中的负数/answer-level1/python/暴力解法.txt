### 解题思路

根据gird的行和列都是递减的规律
遍历grid的每一行，当遇到小于0的值时就跳出循环。
因为后面所有的值都小于0

### 代码

```python3
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:

       m = len(grid)
       n = len(grid[0])

       if grid[m-1][n-1] >=0:
           return 0
       if  grid[0][0] < 0:
           return m*n
       col = n
       count = 0
       for i in range(m):
           for j in range(col):
               if grid[i][j] < 0:
                   count = count + (n-j)
                   break
       return  count

```