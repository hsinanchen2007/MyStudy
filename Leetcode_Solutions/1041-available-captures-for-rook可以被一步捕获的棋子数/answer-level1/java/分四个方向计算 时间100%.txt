### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int row = 0;
        int col = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < board.length; i++) {
            if (board[i][col] == 'p') {
                boolean flag = true;
                if (i < row) {
                    for (int j = i+1; j < row; j++) {
                        if (board[j][col] != '.') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        count++;
                } else {
                    for (int j = row + 1; j < i; j++) {
                        if (board[j][col] != '.') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        count++;
                }
            }
        }
        for (int i = 0; i < board[0].length; i++) {
            if (board[row][i] == 'p') {
                boolean flag = true;
                if (i < col) {
                    for (int j = i+1; j < col; j++) {
                        if (board[row][j] != '.') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        count++;
                } else {
                    for (int j = col + 1; j < i; j++) {
                        if (board[row][j] != '.') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        count++;
                }
            }
        }
        return count;
    }
}
```