井字棋的胜利条件是存在一行、一列或者一条对角线上有3个相同的棋子，因此用数组记录行、列、对角线上双方的棋子数量，如果某方的棋子数量达到3即为获胜。
如果不存在棋子数量达到3的行、列或对角线，则结果是平局或未结束。此时看双方总步数是否达到棋盘大小，达到则是平局，未达到则是未结束。
```
class Solution {
    public String tictactoe(int[][] moves) {
        final char[] SIGNALS = {'X', 'O'};
        final int SIDE = 3;
        char[][] board = new char[SIDE][SIDE];
        int[][] countRows = new int[2][SIDE];
        int[][] countColumns = new int[2][SIDE];
        int[][] countDiagonals = new int[2][2];
        int length = moves.length;
        for (int i = 0; i < length; i++) {
            int player = i % 2;
            int[] move = moves[i];
            int row = move[0], column = move[1];
            board[row][column] = SIGNALS[player];
            int countRow = countRows[player][row];
            countRow++;
            countRows[player][row] = countRow;
            if (countRow == SIDE)
                return player == 0 ? "A" : "B";
            int countColumn = countColumns[player][column];
            countColumn++;
            countColumns[player][column] = countColumn;
            if (countColumn == SIDE)
                return player == 0 ? "A" : "B";
            if (row == column) {
                int countDiagonal = countDiagonals[player][0];
                countDiagonal++;
                countDiagonals[player][0] = countDiagonal;
                if (countDiagonal == SIDE)
                    return player == 0 ? "A" : "B";
            }
            if (row + column == SIDE - 1) {
                int countDiagonal = countDiagonals[player][1];
                countDiagonal++;
                countDiagonals[player][1] = countDiagonal;
                if (countDiagonal == SIDE)
                    return player == 0 ? "A" : "B";
            }
        }
        if (length == SIDE * SIDE)
            return "Draw";
        else
            return "Pending";
    }
}
```
