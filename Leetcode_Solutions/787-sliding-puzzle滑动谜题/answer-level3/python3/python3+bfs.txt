### 解题思路
转换成字符串再bfs，还有很大优化空间

### 代码

```python3
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        def tostring(board):
            s = ''
            for i in range(len(board)):
                for j in range(len(board[0])):
                    s += str(board[i][j])
            return s

        def toBoard(s):
            board = [[0 for _ in range(3)] for _ in range(2)]
            for i in range(6):
                board[i//3][i%3] = int(s[i])
            return board


        def getnexts(cur):
            res = []
            board_cur = toBoard(cur)
            for i in range(6):
                if board_cur[i // 3][i % 3] == 0:
                    break
            zero = i
            zx = zero //3
            zy = zero % 3
            for i,j in d:
                tmp_x = zx + i
                tmp_y = zy + j
                if 0 <= tmp_x < 2 and 0 <= tmp_y < 3:
                    board_cur[zx][zy],board_cur[tmp_x][tmp_y] = board_cur[tmp_x][tmp_y],board_cur[zx][zy]
                    res.append(tostring(board_cur))
                    board_cur[zx][zy],board_cur[tmp_x][tmp_y] = board_cur[tmp_x][tmp_y],board_cur[zx][zy]
            return res

        stack = []
        visited = {}
        d = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        init = tostring(board)
        if init == '123450':
            return 0
        stack.append(init)
        visited[init] = 0
        while stack:
            cur = stack.pop(0)
            nexts = getnexts(cur)
            for s in nexts:
                if s not in visited:
                    stack.append(s)
                    visited[s] = visited[cur] + 1
                    if s == '123450':
                        return visited[s]
        return -1
```