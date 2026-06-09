```
public class TicTacToe {

    private int[] rows;
    private int[] cols;
    private int dj;
    private int xdj;
    private int size;

    /**
     * Initialize your data structure here.
     */
    public TicTacToe(int n) {
        rows = new int[n];
        cols = new int[n];
        dj = 0;
        xdj = 0;
        size = n;
    }

    /**
     * Player {player} makes a move at ({row}, {col}).
     *
     * @param row    The row of the board.
     * @param col    The column of the board.
     * @param player The player, can be either 1 or 2.
     * @return The current winning condition, can be either:
     * 0: No one wins.
     * 1: Player 1 wins.
     * 2: Player 2 wins.
     */
    public int move(int row, int col, int player) {
        int num = player == 1 ? 1 : -1;
        rows[row] += num;
        cols[col] += num;
        if (row == col) {
            dj += num;
        }
        if (row == size - 1 - col) {
            xdj += num;
        }
        if (Math.abs(rows[row]) == size
                || Math.abs(cols[col]) == size
                || Math.abs(dj) == size
                || Math.abs(xdj) == size) {
            return player;
        }
        return 0;
    }
}
```
