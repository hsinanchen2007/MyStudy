拿到题目的第一想法是BFS（官方的多源广度优先搜索）。因为平时都在VSCode上刷LeetCode，当我打开Tags验证想法时，发现是hash-table，再加上题目所属类别是easy，我不禁想入沉思，有更讨巧的做法？直到我百思不得其解打开官方题解。。。。所以hash-table是什么鬼？
![image.png](https://pic.leetcode-cn.com/b9e8648fdad9efcc8b532e402ceccd73b77e7183cd1563a4a7ed30ec87c83a40-image.png)


```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:return 0
        n = len(grid[0])

        def isValid(row,col):
            if row<0 or row>=m or col<0 or col>=n:return False
            return True

        visited = [[False]*n for _ in range(m)]
        good_oranges = 0
        bad_oranges = []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    bad_oranges.append([i,j])
                    visited[i][j] = True
                elif grid[i][j] == 1:
                    good_oranges += 1
                else:
                    visited[i][j] = True
        minutes = 0
        directions = [[-1,0],[1,0],[0,-1],[0,1]]
        
        cnt = 0
        while bad_oranges:
            currLen = len(bad_oranges)

            for i in range(currLen):
                row,col = bad_oranges.pop(0)
                for d in directions:
                    nextRow = row + d[0]
                    nextCol = col + d[1]
                    if not isValid(nextRow, nextCol) or visited[nextRow][nextCol]:continue
                    visited[nextRow][nextCol] = True
                    bad_oranges.append([nextRow, nextCol])
                    cnt += 1
            if len(bad_oranges) == 0: break
            minutes += 1

        return -1  if good_oranges > cnt else minutes
```
