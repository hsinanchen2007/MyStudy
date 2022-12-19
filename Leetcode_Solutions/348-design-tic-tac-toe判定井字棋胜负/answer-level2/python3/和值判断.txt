### 解题思路
- 令棋盘默认值为0
- 玩家1 令该点加一
- 玩家2 令该点减一

记录行，列与对角线的和值
每次只需判断是否出现 n,-n即可
- n: 表示玩家1获胜
- -n: 表示玩家2获胜

### 代码

```python
class TicTacToe:

    def __init__(self, n: int):
        """
        Initialize your data structure here.
        """
        self.edges = n
        self.data = [[0 for _ in range(n)] for _ in range(n)]
        self.rows = [0] * n
        self.cols = [0] * n
        self.left_bottom = 0
        self.right_bottom = 0

    def move(self, row: int, col: int, player: int) -> int:
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        """
        if self.data[row][col] == 0:

            cur = 1 if player == 1 else -1
            self.data[row][col] = cur
            self.rows[row] += cur
            self.cols[col] += cur

            if row == col:
                self.left_bottom += cur
            if row + col == self.edges - 1:
                self.right_bottom += cur

            judge = [self.rows[row], self.cols[col], self.left_bottom, self.right_bottom]
            if -self.edges in judge:
                return 2
            if self.edges in judge:
                return 1

        return 0

# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
```