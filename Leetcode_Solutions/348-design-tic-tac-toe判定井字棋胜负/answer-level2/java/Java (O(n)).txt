### 解题思路
井字棋每次判断的思路是：判断下子的时候，当前所在的行以及所在的列（某些情况下是两条斜边）是否已经构成三个同样的子。所以理论上只需要O(n)时间。

### 代码

```java
class TicTacToe {
    int[][] board;
    int rows;
    int cols;
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        board = new int[n][n];
        rows = n;
        cols = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        board[row][col] = player;

        // check related row
        for (int i = 0; i < rows; i++){
            if (board[row][i] != player){
                break;
            }
            if (i == rows - 1){
                return player;
            }
        }

        // check related col
        for (int i = 0; i < cols; i++){
            if (board[i][col] != player){
                break;
            }
            if (i == cols - 1){
                return player;
            }
        }

        // check diagonal \
        if (row == col){
            for (int i = 0; i < rows; i++){
                if (board[i][i] != player){
                    break;
                } 
                if (i == rows - 1){
                    return player;
                }
            }
        }

        // check diagonal /
        if (row + col == rows - 1){
            for (int i = 0; i < rows; i++){
                if (board[i][rows - 1 - i] != player){
                    break;
                }
                if (i == rows - 1){
                    return player;
                }
            }
        }

        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
```