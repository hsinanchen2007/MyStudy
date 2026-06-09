### 解题思路
遍历边缘，找到‘O’，然后dfs or bfs

### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:
            return 0
        row = len(board)
        col = len(board[0])
        direction = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        def dfs(i,j):
            if board[i][j] == 'O':
                board[i][j] = 'T'
                for x,y in direction:
                    temp_i = i+x
                    temp_j = j+y
                    if 0<temp_i<row and 0<temp_j<col and board[temp_i][temp_j]=='O':
                        dfs(temp_i,temp_j)
        
        for i in range(col):
            dfs(0,i)
            dfs(row-1,i)
        for j in range(row):
            dfs(j,0)
            dfs(j,col-1)
        for i in range(row):
            for j in range(col):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "T":
                    board[i][j] = "O"


```