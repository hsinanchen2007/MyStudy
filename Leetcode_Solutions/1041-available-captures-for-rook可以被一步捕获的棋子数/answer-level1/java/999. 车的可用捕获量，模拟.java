### 解题思路
确实是阅读理解题，没见过国际象棋的车能**一次移动捕获四个方向的卒**。

### 代码
```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int numRookCaptures = 0;
        int[] dx = new int[] {1, -1, 0, 0};
        int[] dy = new int[] {0, 0, 1, -1};
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == 'R' || board[i][j] == 'r') {
                    char bishop = 'B';
                    char pawn = 'p';
                    if (board[i][j] == 'r') {
                        bishop = 'b';
                        pawn = 'P';
                    }
                    for (int k = 0; k < dx.length; ++k) {
                        numRookCaptures += capturePawnNum(board, i, j, dx[k], dy[k], bishop, pawn);
                    }
                    return numRookCaptures;
                } 
            }
        }
        return numRookCaptures;
    }

    /**
     *
     * @param board 棋盘
     * @param x 车(rock)的x坐标
     * @param y 车(rock)的y坐标
     * @param dx x位移参数
     * @param dy y位移参数
     * @param bishop 象的符号
     * @param pawn 兵的符号
     * @return 用(dx, dy)移动，最多能捕获几个兵
     */
    private int capturePawnNum(char[][] board, int x, int y, int dx, int dy, char bishop, char pawn) {
        x += dx;
        y += dy;
        while (x >= 0 && y >= 0 && x < board.length && y < board[0].length) {
            if (board[x][y] == pawn) {
                return 1;
            } else if (board[x][y] == bishop) {
                return 0;
            }
            x += dx;
            y += dy;
        }
        return 0;
    }
}
```