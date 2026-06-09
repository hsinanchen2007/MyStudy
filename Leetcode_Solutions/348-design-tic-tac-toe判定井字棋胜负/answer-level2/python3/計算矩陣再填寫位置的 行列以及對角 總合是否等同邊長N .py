### 解题思路
計算矩陣再填寫位置的 
行列以及對角 
總合是否等同邊長N 

### 代码

```python3
import numpy as np
class TicTacToe:

    def __init__(self, n: int):
        """
        Initialize your data structure here.
        """
        self.matrix = np.zeros((n,n))
        self.N = n
        

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
        self.matrix[row, col] = player
        COL = np.sum(self.matrix[:, col] == player)
        ROW = np.sum(self.matrix[row, :] == player)
        DIA = [i for i in range(0, self.N)]
        DIA_S = np.sum(self.matrix[DIA, DIA] == player)

        IDIA = [i for i in range(self.N-1, -1, -1)]
        IDIA_S = np.sum(self.matrix[DIA, IDIA] == player)

        if COL == self.N or ROW == self.N or DIA_S == self.N or IDIA_S == self.N:
            return player
        else :
             return 0    



# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
```