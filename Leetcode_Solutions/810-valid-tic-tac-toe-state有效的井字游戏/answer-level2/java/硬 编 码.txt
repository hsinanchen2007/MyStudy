```java
class Solution {
    private char[][] ch_board;

    public boolean validTicTacToe(String[] board) {
        ch_board = new char[3][3];
        ch_board[0] = board[0].toCharArray();
        ch_board[1] = board[1].toCharArray();
        ch_board[2] = board[2].toCharArray();
        int X_count = 0, O_count = 0;
        for (int i = 0; i < 3; ++i)
            for (char ch : ch_board[i]) {
                if (ch == 'X')
                    ++X_count;
                else if (ch == 'O')
                    ++O_count;
            }
        return (O_count <= X_count && X_count - O_count <= 1)
                && (!is_win('X') || X_count != O_count)
                && (!is_win('O') || X_count <= O_count);
    }

    private boolean is_win(char ch) {
        return (ch_board[0][0] == ch && ch_board[0][1] == ch && ch_board[0][2] == ch)   //横轴
                || (ch_board[1][0] == ch && ch_board[1][1] == ch && ch_board[1][2] == ch)
                || (ch_board[2][0] == ch && ch_board[2][1] == ch && ch_board[2][2] == ch)
                //纵轴
                || (ch_board[0][0] == ch && ch_board[1][0] == ch && ch_board[2][0] == ch)
                || (ch_board[0][1] == ch && ch_board[1][1] == ch && ch_board[2][1] == ch)
                || (ch_board[0][2] == ch && ch_board[1][2] == ch && ch_board[2][2] == ch)
                //对角线
                || (ch_board[0][0] == ch && ch_board[1][1] == ch && ch_board[2][2] == ch)
                || (ch_board[0][2] == ch && ch_board[1][1] == ch && ch_board[2][0] == ch);
    }
}
```
