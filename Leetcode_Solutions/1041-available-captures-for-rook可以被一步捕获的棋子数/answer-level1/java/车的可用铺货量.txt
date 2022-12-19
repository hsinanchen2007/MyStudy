### 解题思路
简单的dfs

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int result = 0;
        for (int i = 0 ; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    result += up(board, i, j);
                    result += down(board, i, j);
                    result += left(board, i, j);
                    result += right(board, i, j);
                }
            }
        }
        return result;
    }
    public int up(char[][]board, int curX, int curY) {
        if (curX < 0 || curX >= board.length || curY < 0 || curY >= board[0].length || board[curX][curY] == 'B') {
            return 0;
        }
        if (board[curX][curY] == 'p') {
            return 1;
        }
        return up(board, curX-1, curY);
    }
    public int down(char[][]board, int curX, int curY) {
        if (curX < 0 || curX >= board.length || curY < 0 || curY >= board[0].length || board[curX][curY] == 'B') {
            return 0;
        }
        if (board[curX][curY] == 'p') {
            return 1;
        }
        return down(board, curX+1, curY);
    }
    public int left(char[][]board, int curX, int curY) {
        if (curX < 0 || curX >= board.length || curY < 0 || curY >= board[0].length || board[curX][curY] == 'B') {
            return 0;
        }
        if (board[curX][curY] == 'p') {
            return 1;
        }
        return left(board, curX, curY-1);
    }
    public int right(char[][]board, int curX, int curY) {
        if (curX < 0 || curX >= board.length || curY < 0 || curY >= board[0].length || board[curX][curY] == 'B') {
            return 0;
        }
        if (board[curX][curY] == 'p') {
            return 1;
        }
        return right(board, curX, curY+1);
    }
}
```