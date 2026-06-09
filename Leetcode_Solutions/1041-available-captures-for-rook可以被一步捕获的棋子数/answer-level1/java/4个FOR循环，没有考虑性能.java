### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int ROW = -1;
        int COL = -1;
        int nums = 0;
        for (int i = 0; i < board.length; i ++) {
            for (int j = 0; j < board.length; j++) {
                if (board[i][j] == 'R')  {
                    ROW = i;
                    COL = j;
                }
            }
        }
        for (int i = ROW + 1; i < board.length; i++) {
            if (board[i][COL] == 'B') {
                break;
            }
            if (board[i][COL] == 'p') {
                nums ++;
                break;
            }
        }

        for (int i = ROW - 1; i >= 0 ; i--) {
            if (board[i][COL] == 'B') {
                break;
            }
            if (board[i][COL] == 'p') {
                nums ++;
                break;
            }
        }

        for (int j = COL + 1; j < board.length; j++) {
            if (board[ROW][j] == 'B') {
                break;
            }
            if (board[ROW][j] == 'p') {
                nums ++;
                break;
            }
        }

        for (int j = COL - 1; j >= 0; j--) {
            if (board[ROW][j] == 'B') {
                break;
            }
            if (board[ROW][j] == 'p') {
                nums ++;
                break;
            }
        }


        return nums;
    }
}
```