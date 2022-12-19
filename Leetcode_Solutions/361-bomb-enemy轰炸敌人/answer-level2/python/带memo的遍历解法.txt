思路来源于油管上一个小姐姐的思路https:[LeetCode 361. Bomb Enemy 中文解释 Chinese Version](https://www.youtube.com/watch?v=WWVQq_OrgQs)，对普通的暴力解法进行了小幅升级
```
class Solution(object):
    def maxKilledEnemies(self, grid):
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        cols = [0 for i in xrange(n)]
        res = 0
        
        def find(x, y):
            now = rows + cols[y]
            xn = x
            while x < m:
                if grid[x][y] == 'E':
                    now += 1
                elif grid[x][y] == 'W':
                    break
                x += 1
                    
            while y < n:
                if grid[xn][y] == 'E':
                    now += 1
                elif grid[xn][y] == 'W':
                    break
                y += 1
            return now
                    
        for i in xrange(len(grid)):
            rows = 0
            for j in xrange(n):
                if grid[i][j] == 'E':
                    rows += 1
                    cols[j] += 1
                elif grid[i][j] == 'W':
                    rows = 0
                    cols[j] = 0
                else:
                    res = max(res, find(i, j))
                    
        return res
```
