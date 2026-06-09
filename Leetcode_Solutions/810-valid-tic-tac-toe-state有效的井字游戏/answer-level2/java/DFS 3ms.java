```
class Solution {
    public boolean validTicTacToe(String[] board) {
        char[][] newBoard = new char[3][3];
        for (int i = 0; i < board.length; i++) {
            newBoard[i] = board[i].toCharArray();
        }
        int num = 0;
        char[][] mark = new char[3][3]; // 标志位
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (newBoard[i][j] != ' ') {
                    num++; // 记录棋子数量
                }
                mark[i][j] = ' ';
            }
        }

        return dfs(mark, newBoard, true, num);
    }

    public boolean dfs(char[][] mark, char[][] board, boolean flag, int num) {
        if (num == 0) { // 棋子数量为0，则终止
            return true;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mark[i][j] == ' ' && board[i][j] == 'X' && flag) { // 下'X'
                    mark[i][j] = 'X';
                    if ((check(mark) && num - 1 != 0) || !dfs(mark, board, !flag, num - 1)) { // 两种情况需要回溯，重新下棋
                        mark[i][j] = ' '; // 情况1：当前下完满足结束并且棋子数量不为0；情况2：后续的dfs返回false（后面下棋不满足）
                        continue;
                    }
                    return true; // 返回true            
                } else if (mark[i][j] == ' ' && board[i][j] == 'O' && !flag) { // 下'O'
                    mark[i][j] = 'O';
                    if ((check(mark) && num - 1 != 0) || !dfs(mark, board, !flag, num - 1)) { // 同上
                        mark[i][j] = ' ';
                        continue;
                    }
                    return true;    
                }
            }
        }
        
        return false; // 前面遍历都未找到满足的下棋方式，返回false
    }
    
    /* 是否满足结束条件 */
    public boolean check(char[][] board) {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == 'X' || board[i][0] == 'O') && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return true;
            }
            if ((board[0][i] == 'X' || board[0][i] == 'O') && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
                return true;
            }
        }
        if ((board[0][0] == 'X' || board[0][0] == 'O') && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return true;
        }
        if ((board[0][2] == 'X' || board[0][2] == 'O') && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true;
        }
        return false;
    }
}
```
