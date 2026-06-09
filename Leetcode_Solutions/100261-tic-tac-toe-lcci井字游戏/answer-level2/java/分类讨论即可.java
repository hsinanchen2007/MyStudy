# 代码
```java
class Solution {
    private char[][] ch_board;
    private int len;

    public String tictactoe(String[] board) {
        len = board.length;
        ch_board = new char[len][len];
        for (int i = 0; i < len; ++i)
            ch_board[i] = board[i].toCharArray();

        int X_count = 0, O_count = 0;
        for (int i = 0; i < len; ++i)
            for (char ch : ch_board[i]) {
                if (ch == 'X')
                    ++X_count;
                else if (ch == 'O')
                    ++O_count;
            }
        //没下满棋盘
        if (X_count + O_count < len * len) {
            if (is_win('X'))
                return "X";
            if (is_win('O'))
                return "O";
            return "Pending";
        }
        //下满棋盘
        if (is_win('X'))
            return "X";
        if (is_win('O'))
            return "O";
        return "Draw";
    }

    private boolean is_win(char ch) {
        search_row: //横向
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j)
                if (ch_board[i][j] != ch)
                    continue search_row;
            return true;
        }
        search_col: //纵向
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i < len; ++i)
                if (ch_board[i][j] != ch)
                    continue search_col;
            return true;
        }
        boolean found = true;
        //正对角线
        for (int i = 0; i < len; ++i)
            if (ch_board[i][i] != ch) {
                found = false;
                break;
            }
        if (found) return true;
        found = true;
        //逆对角线
        for (int i = 0; i < len; ++i)
            if (ch_board[i][len - i - 1] != ch) {
                found = false;
                break;
            }

        return found;
    }
}
```
