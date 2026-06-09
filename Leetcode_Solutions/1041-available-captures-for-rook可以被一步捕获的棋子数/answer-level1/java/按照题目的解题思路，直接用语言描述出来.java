### 解题思路
我的解法主要是暴力解法，按照题意直接写出来的，从上下左右四个方向直接找出来，可能因为8*8的棋盘，所以时间复杂度并不高

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
    int x = 0;//行
        int y = 0;//列
        int res = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                }
            }
        }
        //左边
        for (int j = y; j >=0; j--) {
            if (board[x][j] == 'B') {
                break;
            } else if (board[x][j] == 'p') {
                res++;break;
            }


        }
        //右边
        for (int j = y + 1; j < 8; j++) {
            if (board[x][j] == 'B') {
                break;
            } else if (board[x][j] == 'p') {
                res++;break;
            }
        }

        //上边
        for (int j = x; j >=0; j--) {
            if (board[j][y] == 'B') {
                break;
            } else if (board[j][y] == 'p') {
                res++;break;
            }


        }
        //下边
        for (int j = x + 1; j < 8; j++) {
            if (board[j][y] == 'B') {
                break;
            } else if (board[j][y] == 'p') {
                res++;break;
            }
        }
        return res;
    }
}
```