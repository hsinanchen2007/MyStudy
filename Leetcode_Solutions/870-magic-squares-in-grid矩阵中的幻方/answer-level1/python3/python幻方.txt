可以先找出所有三阶幻方，再来求个数
```
class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        l = [[8, 1, 6, 3, 5, 7, 4, 9, 2],
             [6, 1, 8, 7, 5, 3, 2, 9, 4],
             [4, 9, 2, 3, 5, 7, 8, 1, 6],
             [2, 9, 4, 7, 5, 3, 6, 1, 8],
             [6, 7, 2, 1, 5, 9, 8, 3, 4],
             [8, 3, 4, 1, 5, 9, 6, 7, 2],
             [2, 7, 6, 9, 5, 1, 4, 3, 8],
             [4, 3, 8, 9, 5, 1, 2, 7, 6]]
        
        count = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                temp = grid[i][j:j + 3] + grid[i + 1][j:j + 3] + grid[i + 2][j:j + 3]
                if temp in l:
                    count += 1
        return count
```
