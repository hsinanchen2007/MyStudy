首先找到需要回溯的第一个点 即在二维数组中找到word中的第一个值
用一个二维数组tag标记已经走过的点

回溯思想很简单 
一个函数 入参是 当前剩下的word和在数组中的位置row col
往上下左右四个方向走 如果有一个方向的字符是与当前word[0]相等的字符 就往这个方向走下去传入word.subString(0)继续回溯

注意回溯中
    1.如果已经得到了true的结果 就return 否则超时
    2.判断是否超出边界

```
class Solution {
    int[][] tag;
    char[][] board;
    boolean res = false;
    int rows, cols;

    public void backtrack(String word, int row, int col) {
        if (word.length() == 0) {
            res = true;
            return;
        }

        if(res) return;
        
        // 向右走
        if (col + 1 != cols && tag[row][col + 1] == 0 && word.charAt(0) == board[row][col + 1]) {
            tag[row][col + 1] = 1;
            backtrack(word.substring(1), row, col + 1);
            tag[row][col + 1] = 0;
        }
        
        // 向左走
        if (col - 1 != -1 && tag[row][col - 1] == 0 && word.charAt(0) == board[row][col - 1]) {
            tag[row][col - 1] = 1;
            backtrack(word.substring(1), row, col - 1);
            tag[row][col - 1] = 0;
        }

        // 向下走
        if (row + 1 != rows && tag[row + 1][col] == 0 && word.charAt(0) == board[row + 1][col]) {
            tag[row + 1][col] = 1;
            backtrack(word.substring(1), row + 1, col);
            tag[row + 1][col] = 0;
        }

        // 向上走
        if (row - 1 != -1 && tag[row - 1][col] == 0 && word.charAt(0) == board[row - 1][col]) {
            tag[row - 1][col] = 1;
            backtrack(word.substring(1), row - 1, col);
            tag[row - 1][col] = 0;
        }
    }

    public boolean exist(char[][] board, String word) {
        if (word.length() == 0) return true;
        else if (board.length == 0) return false;

        int rows = board.length, cols = board[0].length;
        this.rows = rows;
        this.cols = cols;
        this.tag = new int[rows][cols];
        this.board = board;

        if(rows*cols < word.length()) return false;

        // 找到第一个回溯点
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == word.charAt(0)) {
                    tag[row][col] = 1;
                    backtrack(word.substring(1), row, col);
                    tag[row][col] = 0;
                    if(res) return true;
                }
            }
        }

        return false;
    }
}
```
