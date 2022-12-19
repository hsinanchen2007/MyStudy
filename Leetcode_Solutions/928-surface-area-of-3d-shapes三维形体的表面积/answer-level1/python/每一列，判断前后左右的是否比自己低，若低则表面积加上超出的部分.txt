### 解题思路
此处撰写解题思路
当心“堰塞湖”，中间凹下去的部分也是需要算表面积的。
1.每一个点分别判断其6个面是否被遮挡
### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        len1 = len(grid)
        s = 0
        for i in range(0, len1, 1):
            for j in  range(0, len1, 1):
                if i==0:            #behind
                    s += grid[i][j]
                elif i!=0 and grid[i][j] > grid[i-1][j]:
                    s += grid[i][j] - grid[i-1][j]
                if i==len1-1:       #front
                    s += grid[i][j]
                elif i!=len1-1 and grid[i][j] > grid[i+1][j]:
                    s += grid[i][j] - grid[i+1][j]
                if j==0:            #left
                    s += grid[i][j]
                elif j != 0 and grid[i][j] > grid[i][j-1]:
                    s += grid[i][j] - grid[i][j-1]
                if j == len1-1:         #right
                    s += grid[i][j]
                elif j != len1-1 and grid[i][j] > grid[i][j+1]:
                    s += grid[i][j] - grid[i][j+1]
                if grid[i][j] != 0:        #up and down
                    s += 2


        return s
```