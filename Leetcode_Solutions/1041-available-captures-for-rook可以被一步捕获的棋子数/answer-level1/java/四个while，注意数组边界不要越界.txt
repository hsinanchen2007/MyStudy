### 解题思路
本来还想DFS，根据题意，一次运动可攻击，也就是同一行，同一列，第一个碰到的。

### 代码

```java
class Solution {
    int sum = 0;

    public int numRookCaptures(char[][] board) {
        if (board == null || board.length == 0) {
            return 0;
        }
        int row = 0;
        int line = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'R') {
                    row = i;
                    line = j;
                    break;
                }
            }
        }

        int tmpRow1 = row;
        while (tmpRow1 > 0) {
            tmpRow1--;
            if (board[tmpRow1][line] == 'p') {
                sum++;
                break;
            }
            if (board[tmpRow1][line] == 'B') {
                break;
            }
        }

        int tmpRow2 = row;
        while (tmpRow2 < board.length - 1) {
            tmpRow2++;
            if (board[tmpRow2][line] == 'p') {
                sum++;
                break;
            }
            if (board[tmpRow2][line] == 'B') {
                break;
            }
        }

        int tmpLine1 = line;
        while (tmpLine1 > 0) {
            tmpLine1--;
            if (board[row][tmpLine1] == 'p') {
                sum++;
                break;
            }
            if (board[row][tmpLine1] == 'B') {
                break;
            }
        }

        int tmpLine2 = line;
        while (tmpLine2 < board.length - 1) {
            tmpLine2++;
            if (board[row][tmpLine2] == 'p') {
                sum++;
                break;
            }
            if (board[row][tmpLine2] == 'B') {
                break;
            }
        }
        return sum;
    }
}
```