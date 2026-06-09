### 代码

```python3
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board: 
            return 
        row = len(board)
        col = len(board[0])  # 列是len(board[0])，细心
        if row < 3 or col < 3:  # 行或列<3，O必然是裸露的，无需处理
            return
        def dfs(i, j):
            if i < 0 or j < 0 or i >= row or j >= col or board[i][j] != 'O':
                return
            board[i][j] = '#' # 处理边界范围内且与边界连通的O
            dfs(i - 1, j)  # 对其相邻区域也做同样处理；
            dfs(i + 1, j)
            dfs(i, j - 1)
            dfs(i, j + 1)
        for i in range(row):  # 找到围绕区域不易，采用逆向思维，处理边界处的O，找到与之相通的O
            dfs(i, 0)
            dfs(i, col - 1)  # 注意不要越界
        for j in range(col):
            dfs(0, j)
            dfs(row - 1, j)  # 注意不要越界

        for i in range(row):
            for j in range(col):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'
```