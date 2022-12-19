![image.png](https://pic.leetcode-cn.com/2c83f54638e96a0f7af01c1c19897873a9afd95e7998c37da7b4f8025a35ac9c-image.png)

>这题应该算归为简单题吧，直接看每一个点是否合法就行了。

```java
class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] != '.' && !check(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean check(char[][] board, int x, int y) {
        char num = board[x][y];
        // if (x == y) {
        //     // 判断主对角线是否合法
        //     for (int i = 0; i != x && i < board.length; i++) {
        //         if (board[i][i] == num) {
        //             return false;
        //         }
        //     }
        // }
        // if (x + y == n - 1) {
        //     // 判断副对角线是否合法
        //     for (int i = 0; i != x && i < board.length; i++) {
        //         if (board[i][n - 1 - i] == num) {
        //             return false;
        //         }
        //     }
        // }

        // 判断同一行是否合法
        for (int i = 0; i != y && i < board.length; i++) {
            if (board[x][i] == num) {
                return false;
            }
        }

        // 判断同一列是否合法
        for (int i = 0; i != x && i < board.length; i++) {
            if (board[i][y] == num) {
                return false;
            }
        }

        // 判断九宫格内是否合法
        int beginX = 3 * (x / 3);
        int beginY = 3 * (y / 3);
        for (int i = beginX; i < beginX + 3; i++) {
            for (int j = beginY; j < beginY + 3; j++) {
                if (i != x && j != y && board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;

    }
}
```