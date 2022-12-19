### 解题思路
此处撰写解题思路
一个正方体有六个面，当第一个空格上有n个正方体时，那么表面积是 6*n，然后需要减去（n-1） * 2个面，第二个空格上放置为m个正方体时，初了自身增加的4*m +2 ，那么嗨需要减去与空格1正方体重叠的面积，那么就是（m，n）的最小值 *2 个面，依次类推。。。。
### 代码

```python3

class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                m=0
                if grid[i][j] > 1:
                    res += grid[i][j] * 6 - (grid[i][j] -1)*2
                else:
                    res += grid[i][j] * 6 
                if i >=1:
                    m = grid[i-1][j] if grid[i][j] > grid[i-1][j] else grid[i][j]
                    res -= m * 2
                if j >=1:
                    m = grid[i][j-1] if grid[i][j] > grid[i][j-1] else grid[i][j]
                    res -= m * 2     
        return res

```