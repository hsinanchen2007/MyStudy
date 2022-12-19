### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution(object):
    def exist(self, board, word):
        def dfs(x,y,mark,index):
            if index >= len(word):
                return True
            for dx,dy in [(0,1),(0,-1),(1,0),(-1,0)]:
                xi = x + dx
                yi = y + dy
                if 0<=xi<m and 0<=yi<n and board[xi][yi]==word[index]:
                    if mark[xi][yi] == 1:
                        continue
                    mark[xi][yi] = 1
                    if dfs(xi,yi,mark,index+1):
                        return True
                    else:
                        mark[xi][yi] = 0
            return False
        m = len(board)
        n = len(board[0])
        mark = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                index = 0
                if board[i][j]==word[index]:
                    mark[i][j] = 1
                    if dfs(i,j,mark,index+1):
                        return True
                    else:
                        mark[i][j] = 0
        return False
```