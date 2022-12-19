### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        self.cnt = 0
        if not board:
            return self.cnt

        def dfs(r: int, c: int, x: int, y: int):
            while True:
                if x + r < 0 or x + r >= len(board) or y + c < 0 or y + c >= len(board[0]):
                    break
                if board[x + r][y + c] == 'B':
                    break
                if board[x + r][y + c] == 'p':
                    self.cnt += 1
                    return
                x += r
                y += c

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'R':
                    dfs(1, 0, i, j)
                    dfs(- 1, 0, i, j)
                    dfs(0, 1, i, j)
                    dfs(0, - 1, i, j)
        return self.cnt
```