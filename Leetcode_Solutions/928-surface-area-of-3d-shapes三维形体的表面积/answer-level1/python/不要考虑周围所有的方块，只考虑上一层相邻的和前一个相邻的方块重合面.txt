### 解题思路
1，层次遍历所有方块
2，依次将每个格子方块的表面积加入到总表面积，`N*4 +2` 就是 N 个方块堆放在一起的表面积
3，计算每个格子的方块的表面积的时候，只去看它的左侧和上侧相交的方块的重合的面积，即比较矮的那个方块的高度是重合在一起的
4，`min(grid[i][j], grid[i-1][j]) * 2` 即是上方重合需要减去的表面积，同理还有左侧 `min(grid[i][j], grid[i][j-1])*2`
5，只要注意 `i,j` 的有效范围，便可以写出下面的程序了

### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:

        li = len(grid)
        if li == 0:
            return 0
        lj = len(grid[0])
        if lj == 0:
            return 0

        def sumit(i, j):
            if grid[i][j] > 0:
                now = grid[i][j] * 4 + 2
            else:
                now = 0
            rev = 0
            if i == 0:
                if j == 0:
                    rev = now
                else:
                    rev = now - min(grid[i][j], grid[i][j-1]) * 2
            else:
                if j == 0:
                    rev = now - min(grid[i][j], grid[i-1][j]) * 2
                else:
                    rev = now - min(grid[i][j], grid[i-1][j]) * 2 - min(grid[i][j], grid[i][j-1]) * 2
            return rev

        rev = 0
        i = 0
        while i < li:
            j = 0
            while j < lj:
                rev += sumit(i, j)
                j += 1
            i += 1
        return rev



```