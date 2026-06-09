### 解题思路
# 代码很乱各路大神谅解
来说下我的思路：
1. 遍历board列表找到其中“M”所在位置
2. 给"M"周围的格累加1
3. 剩下其他前辈解答的思路差不多啦

### 代码

```python3
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        r = [1, 1, 0, 0, -1, -1, -1, 1]
        c = [0, 1, 1, -1, 1, 0, -1, -1]
        
        
        board1 = [[i for i in board[xx]]for xx in range(len(board))]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'M':
                    for k in range(8):
                        if self.isle(len(board), len(board[0]), i + r[k], j + c[k]):
                            if board[i + r[k]][j + c[k]] == 'E':
                                board[i + r[k]][j + c[k]] = '1'
                            elif not board[i + r[k]][j + c[k]] == 'M':
                                board[i + r[k]][j + c[k]] = str(int(board[i + r[k]][j + c[k]]) + 1)
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = str(board[i][j])
        if not board[click[0]][click[1]] == "E":
            if board[click[0]][click[1]] == 'M':
                board1[click[0]][click[1]] = 'X'
                return board1
            else:
                board1[click[0]][click[1]] = board[click[0]][click[1]]
                return board1
        self.dfs(board, board1, click)
        return board1

    def isle(self, r, l, xx, y) -> bool:
        return r > xx >= 0 and 0 <= y < l

    def dfs(self, board: list, board1: list, click: list):
        r = [1, 1, 0, 0, -1, -1, -1, 1]
        c = [0, 1, 1, -1, 1, 0, -1, -1]
        board1[click[0]][click[1]] = 'B'
        board[click[0]][click[1]] = 'B'
        for i in range(8):
            nr = r[i] + click[0]
            nc = c[i] + click[1]
            if self.isle(len(board), len(board[0]), nr, nc):
                if board[nr][nc] == 'E':
                    click1 = [nr, nc]
                    self.dfs(board, board1, click1)
                elif board1[nr][nc] == 'E':
                    board1[nr][nc] = board[nr][nc]
```