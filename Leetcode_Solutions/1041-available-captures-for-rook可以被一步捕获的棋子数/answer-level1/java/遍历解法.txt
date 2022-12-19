### 解题思路
先遍历找出马的位置坐标，从马出发向四个方向遍历，遇到象或者卒就停下，用变量summ来记录遇到卒的次数

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int x = 0;
        int y = 0;
        int summ = 0;
        for (int i = 0;i < board.length;i++){
            for (int j = 0;j < board.length;j++){
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        for (int i = x;i >= 0;i--){
            if (board[i][y] == 'B'){
                break;
            }
            if (board[i][y] == 'p'){
                summ = summ + 1;
                break;
            }
        }
        for (int i = x;i < board.length;i++){
            if (board[i][y] == 'B'){
                break;
            }
            if (board[i][y] == 'p'){
                summ = summ + 1;
                break;
            }
        }
        for (int i = y;i >= 0;i--){
            if (board[x][i] == 'B'){
                break;
            }
            if (board[x][i] == 'p'){
                summ = summ + 1;
                break;
            }
        }
        for (int i = y;i < board.length;i++){
            if (board[x][i] == 'B'){
                break;
            }
            if (board[x][i] == 'p'){
                summ = summ+ 1;
                break;
            }
        }
        return summ;
    }
}
```