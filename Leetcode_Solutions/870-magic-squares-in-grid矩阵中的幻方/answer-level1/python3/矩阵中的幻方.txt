### 解题思路
按照题设思路一条条验证，没什么技巧，仅供参考

### 代码

```python3
class Solution():
    def numMagicSquaresInside(self,grid):
        #取维度
        row_len = len(grid)
        col_len = len(grid[0])
        rst = 0
        #验证循环条件
        if (row_len >= 3) & (col_len >= 3):
            #行循环，列循环
            for row in range(row_len-2):
                for col in range(col_len-2):
                    #3行list合并
                    List_check = []
                    List_check.extend(grid[row][col:col+3])
                    List_check.extend(grid[row+1][col:col+3])
                    List_check.extend(grid[row+2][col:col+3])
                    #验证是否含有9位数字
                    if all([(i in List_check) for i in range(1,10)]):
                        #验证8个求和是否相等，此处应该可以优化简写
                        maxtrix_sum = grid[row][col] + grid[row][col+1] + grid[row][col+2]
                        if (maxtrix_sum == grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2]):
                            if (maxtrix_sum == grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2]):
                                if (maxtrix_sum == grid[row][col] + grid[row+1][col] + grid[row+2][col]):
                                    if (maxtrix_sum == grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1]):
                                        if (maxtrix_sum == grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2]):
                                            if (maxtrix_sum == grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2]):
                                                if (maxtrix_sum == grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col]):
                                                    rst += 1
        return rst
```