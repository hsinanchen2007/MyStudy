由于边缘不算，那就先把边缘的 `O` 存起来换成其他的字符，然后再对内部的 `O` 全部替换成 `X`，最后将边缘位置区块再换回来即可。
由于都是 floodfill ，那么就复用方法逻辑：

**注意空数组的边界条件**

```python
class Solution:
    def __init__(self):
        self.board = []
        
    def prt(self):
        for i in self.board:
            print(i)
        
    def dfs(self, x, y, ch):
        self.board[x][y] = ch
        if x - 1 >= 0 and self.board[x - 1][y] == 'O':
            self.dfs(x - 1, y, ch)
        if x + 1 < len(self.board) and self.board[x + 1][y] == 'O':
            self.dfs(x + 1, y, ch)    
        if y - 1 >= 0 and self.board[x][y - 1] == 'O':
            self.dfs(x, y - 1, ch)    
        if y + 1 < len(self.board[0]) and self.board[x][y + 1] == 'O':
            self.dfs(x, y + 1, ch)    
    
    def solve(self, board: List[List[str]]) -> None:
        self.board = board
        if len(board) <= 0 or len(board[0]) <= 0:
            return board
        # 先处理边缘位置
        for i in [0, len(board) - 1]:
            for j in range(0, len(board[0])):
                if self.board[i][j] == 'O':
                    self.dfs(i, j, '$')
                    
        for j in [0, len(board[0]) - 1]:
            for i in range(0, len(board)):
                if self.board[i][j] == 'O':
                    self.dfs(i, j, '$')
                    
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.board[i][j] == 'O':
                    self.dfs(i, j, 'X')
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.board[i][j] == '$':
                    self.board[i][j] = 'O'
                    
        # self.prt()            
        return self.board
```