思路很简单，x, o不能同时赢，并且它们出现的数量有约束关系。
但要考虑完所有情况却不容易，只好面向测试用例编程了……

```c++
class Solution {
    public boolean validTicTacToe(String[] board) {
        int cnto = 0, cntx = 0;
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++) {
                if (board[i].charAt(j) == 'O') cnto ++;
                else if (board[i].charAt(j) == 'X') cntx ++;
            }
        if (cntx - cnto > 1 || cntx < cnto) return false;

        boolean oWin = false, xWin = false;

        for (int i = 0; i < 3; i ++) {
            if (board[i].charAt(0) == 'O' && board[i].charAt(1) == 'O' && board[i].charAt(2) == 'O') {
                oWin = true;
            } else if (board[i].charAt(0) == 'X' && board[i].charAt(1) == 'X' && board[i].charAt(2) == 'X') {
                xWin = true;
            }
        }

        for (int i = 0; i < 3; i ++) {
            if (board[0].charAt(i) == 'O' && board[1].charAt(i) == 'O' && board[2].charAt(i) == 'O') {
                oWin = true;
            } else if (board[0].charAt(i) == 'X' && board[1].charAt(i) == 'X' && board[2].charAt(i) == 'X') {
                xWin = true;
            }
        }

        if (board[0].charAt(0) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(2) && board[0].charAt(0) != ' ') {
            if (board[0].charAt(0) == 'O') oWin = true;
            else xWin = true;
        }

        if (board[0].charAt(2) == board[1].charAt(1) && board[1].charAt(1) == board[2].charAt(0) && board[0].charAt(2) != ' ') {
            if (board[0].charAt(2) == 'O') oWin = true;
            else xWin = true;
        }

        if (oWin && xWin) return false;
        if (xWin && (cntx == cnto)) return false;
        if (oWin && (cntx != cnto)) return false;
        return true;
    }
}
```