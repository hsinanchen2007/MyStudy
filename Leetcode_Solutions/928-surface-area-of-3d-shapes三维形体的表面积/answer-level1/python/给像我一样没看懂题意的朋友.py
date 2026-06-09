### 解题思路
我看了很久没看懂题意, 其实题目的意思是: 

在一个**平面**(m * n)上, 有m*n个边长是1的小格子, 每个小格子中放置若干个小正方体, 最后求整个平面上
由这些小格子形成的立体图形的表面积.

或者再具体一点, 把这个平面看成是一个棋盘, 在每个棋盘的格子中放小正方体, ...

理解了以上解释再去看 [weiwei大神](https://leetcode-cn.com/problems/surface-area-of-3d-shapes/solution/hua-tu-ji-suan-san-ge-zhong-die-bu-fen-by-liweiwei/)  的理解就很容易懂了.


### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        count = 0
        rowOverlap = 0
        colOverlap = 0
        verticalOverlap = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                count += grid[i][j];
                if grid[i][j] > 1: verticalOverlap += grid[i][j] - 1
                if i > 0:
                    colOverlap += min(grid[i-1][j], grid[i][j])
                if j > 0:
                    rowOverlap += min(grid[i][j-1], grid[i][j])
        return count * 6 - (rowOverlap + colOverlap + verticalOverlap) * 2
```