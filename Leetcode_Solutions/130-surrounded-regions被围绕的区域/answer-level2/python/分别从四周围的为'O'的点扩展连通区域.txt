### 解题思路
分别从四周围的为'O'的点扩展连通区域
160ms

### 代码

```python
class Solution(object):
    def checkConnect(self, board, m, n, a, b):
        stack = [(a,b)]
        # 方向 上右下左
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        while stack:
            i, j = stack.pop(0)
            board[i][j] = 'C'

            for d in directions:
                a, b = (i + d[0], j + d[1])
                if 0 <= a < m and 0 <= b < n:
                    if board[a][b] == 'O' and (a,b) not in stack:
                        stack.append((a,b))

    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        m = len(board)
        if m <= 1: return
        n = len(board[0])

        # 检查上下
        for i in (0, m-1):
            for j in range(n):
                if board[i][j] == 'O':
                    self.checkConnect(board, m, n, i, j)

        # 检查左右
        for i in range(m):
            for j in (0, n-1):
                if board[i][j] == 'O':
                    self.checkConnect(board, m, n, i, j)

        # 重新
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'C':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
                 
```