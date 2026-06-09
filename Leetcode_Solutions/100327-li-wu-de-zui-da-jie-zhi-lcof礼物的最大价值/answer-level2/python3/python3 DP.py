![SharedScreenshot.jpg](https://pic.leetcode-cn.com/648f391c687833af278671c0a6cf5410a18ed3b0aa3b86b6a6487ff83ca384ed-SharedScreenshot.jpg)

```
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        for row in range(len(grid)):
            for column in range(len(grid[0])):
                if row and column:
                    grid[row][column] += (a if (a := grid[row - 1][column]) > (b := grid[row][column - 1]) else b)
                
                elif column:
                    grid[row][column] += grid[row][column - 1]
                    
                elif row:
                    grid[row][column] += grid[row - 1][column]

        return grid[-1][-1]
```
