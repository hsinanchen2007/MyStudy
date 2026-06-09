### 解题思路
直到我提交了几次之后，发现，emmm是 字母 O 不是 数字 0
### 代码
```python
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board or not board[0]:return None
        row, col = len(board), len(board[0])
        if row <= 2 or col <= 2 : return None
        dx, dy = [0, 0, -1, 1], [1, -1, 0, 0] #front change
        #helper dfs
        def dfs(x, y):
            board[x][y] = '*' #mark '0' to '*' and search item around it
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < row and 0 <= ny < col and board[nx][ny]=='O': dfs(nx, ny)
        #four edge search '0'
        for x in range(row):
            for y in [0,col-1]:
                if board[x][y] == 'O':dfs(x, y)
        for x in [0,row-1]:
            for y in range(col):
                if board[x][y] == 'O':dfs(x, y)
        # mark change in all items
        for x in range(row):
            for y in range(col):
                if board[x][y] == '*':board[x][y] = 'O'
                else:board[x][y] = 'X'
```