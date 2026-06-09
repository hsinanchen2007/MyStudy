### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        //bad-case
        if (board.length == 0 || board[0].length == 0) {
            return 0;
        }

        //找到车的位置 记录行号列号
        int row = -1;
        int col = -1;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                }
            }
        }

        if (row == -1 || col == -1) {
            return 0;
        }

        //四个方向开始遍历并计数
        int left = 0;
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'B') {
                break;
            }
            if (board[i][col] == 'p') {
                left = 1;
            }
        }

        int right = 0;
        for (int i = row; i < board[0].length; i++) {
            if (board[i][col] == 'B') {
                break;
            }
            if (board[i][col] == 'p') {
                right = 1;
            }
        }
        
        int north = 0;
        for (int i = col; i >= 0; i--) {
            if (board[row][i] == 'B') {
                break;
            }
            if (board[row][i] == 'p') {
                north = 1;
            }
        }

        int west = 0;
        for (int i = col; i < board.length; i++) {
            if (board[row][i] == 'B') {
                break;
            }
            if (board[row][i] == 'p') {
                west = 1;
            }
        }

        return (left + right + north + west);
    }
}
```