**解法一**
暴力
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        for row in grid:
            for num in row:
                if num < 0:
                    ans += 1
        return ans 
```
**解法二**
暴力法的改进：提前终止循环。
思路：假设所给矩阵为m行n列，初始化记录列数与行数的变量 col = n，row = m；
按行从左到右的顺序依次遍历，直到首次出现第m-row的第j个元素小于零，则第m-row行的后n-j个元素均为负数，又因为行数越大，元素越小，所以后row行的后n-j个元素均为负。此时记录下负数元素的列数col = j；剩余行数row 减一；
循环遍历，直到某一行的首元素为负数（即col=0）结束遍历 或者遍历完所有行。
```
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        ans = 0
        row , col = len(grid),len(grid[0])
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] < 0:
                    ans += row * (col-j)
                    col = j
                    break
            row -= 1
            if col ==0 :
                break
        return ans 
```
