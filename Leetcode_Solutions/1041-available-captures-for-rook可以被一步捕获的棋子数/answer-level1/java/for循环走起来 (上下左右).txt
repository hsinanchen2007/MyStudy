### 解题思路
上下左右追踪!

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int h = 0;
        int v = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if ('R' == board[i][j]) {
                    h = i;
                    v = j;
                }
            }
        }
        int sum = 0;
        //左
        for (int i = v - 1; i >= 0; i--) {
            if ('B' == board[h][i]) {
                break;
            }
            if ('p' == board[h][i]) {
                sum++;
                break;
            }
        }
        //右
        for (int i = v + 1; i < 8; i++) {
            if ('B' == board[h][i]) {
                break;
            }
            if ('p' == board[h][i]) {
                sum++;
                break;
            }
        }
        //下
        for (int i = h + 1; i < 8; i++) {
            if ('B' == board[i][v]) {
                break;
            }
            if ('p' == board[i][v]) {
                sum++;
                break;
            }
        }
        //上
        for (int i = h - 1; i >= 0; i--) {
            if ('B' == board[i][v]) {
                break;
            }
            if ('p' == board[i][v]) {
                sum++;
                break;
            }
        }
        return sum;
    }
}
```