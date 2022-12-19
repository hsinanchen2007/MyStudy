```
class TicTacToe:

    def __init__(self, n: int):
        """
        Initialize your data structure here.
        """
        self.cols = [[0 for i in range(n)] for j in range(2)]
        self.rows = [[0 for i in range(n)] for j in range(2)]
        self.angs = [[0 for i in range(2)] for j in range(2)]
        self.n = n
        

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
        self.cols[player-1][col] += 1
        self.rows[player-1][row] += 1
        self.angs[player-1][0] += 1 if (col == row) else 0
        self.angs[player-1][1] += 1 if (col == self.n-1-row) else 0
        if self.n == max(self.cols[player-1][col], self.rows[player-1][row], max(self.angs[player-1])):
            return player
        return 0
```
