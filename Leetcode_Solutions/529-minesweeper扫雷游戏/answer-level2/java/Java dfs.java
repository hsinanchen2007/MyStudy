### 解题思路
注意审题，上下左右且包括对角线。
挖到雷或者相邻有雷的方块时，直接修改所挖块的状态返回就可以了。
挖到相邻没有雷的空方块时就是标准dfs，注意边界条件和八个方向而不是四个方向即可。

### 代码

```java
class Solution {
    private static final int[][] DIRECTION = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
    public char[][] updateBoard(char[][] board, int[] click) {
        if (board.length == 0) {
            return board;
        }
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
        } else if (adjacentMineNum(board, click[0], click[1]) > 0) {
            board[click[0]][click[1]] = (char) (adjacentMineNum(board, click[0], click[1]) + '0');
        } else {
            dfs(board, click[0], click[1]);
        }
        return board;
    }

    private void dfs(char[][] board, int ii, int jj) {
        if (adjacentMineNum(board, ii, jj) > 0) {
            board[ii][jj] = (char)(adjacentMineNum(board, ii, jj)+'0');
            return;
        }
        board[ii][jj] = 'B';
        for (int i = 0; i < 8; i++) {
            int newI = ii + DIRECTION[i][0];
            int newJ = jj + DIRECTION[i][1];
            if (newI >= 0 && newI < board.length && newJ >= 0 && newJ < board[0].length && board[newI][newJ] == 'E') {
                dfs(board, newI, newJ);
            }
        }
    }

    private int adjacentMineNum(char[][] board, int ii, int jj) {
        int res = 0;
        for (int i = ii - 1; i <= ii + 1; i++) {
            for (int j = jj - 1; j <= jj + 1; j++) {
                if (i >= 0 && i < board.length && j >= 0 && j < board[0].length && board[i][j] == 'M') {
                    res++;
                }
            }
        }
        return res;
    }
}
```