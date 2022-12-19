### 解题思路
这题是动态规划很明显了，一开始我采用的方案是创建一个和grid同样大小的列表。随时记录数值

后来发现可以直接使用gird存储动态规划的结果

只需要考虑当元素处于**最左侧**和**最上侧**的特殊情况即可

### 代码

```python
def maxValue(self, grid):
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if i == 0 and j == 0:
                continue
            elif i == 0:
                grid[i][j] = grid[i][j-1] + grid[i][j]
            elif j == 0:
                grid[i][j] = grid[i-1][j] + grid[i][j]
            else:
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j]
    
    return grid[-1][-1]
```