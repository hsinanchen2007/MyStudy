board中只有0和1两种状态，只占用了int的最低位，我们可以把int的高位利用起来

第一次遍历board，当我们确定(i, j)位置的cell更新后的状态是存活，就把高位的值置为1
board[i][j] |= 2

第二次遍历board，把高位挪回低位
board[i][j] >>= 1

```python []
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        offsets = ((-1, -1), (-1, 0), (-1, 1), (0, -1),
                   (0, 1), (1, -1), (1, 0), (1, 1))
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                alive = 0
                for offset in offsets:
                    x, y = i + offset[0], j + offset[1]
                    if x >= 0 and x < m and y >= 0 and y < n:
                        alive += board[x][y] & 1
                if alive == 3 or alive == 2 and board[i][j]:
                    board[i][j] |= 2
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1

```
