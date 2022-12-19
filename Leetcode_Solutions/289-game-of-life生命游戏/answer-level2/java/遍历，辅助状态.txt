### 解题思路
本题的难点在于使用原来二维数组，如果没有这个限制，那么可以用辅助二维数组，很easy。跟辅助数组的作用一样，需要保留中间状态。因为board里的值，不是0就是1，那么可以将board里的每个值增加一个比特位，用于保存中间状态，至于用什么状态可以自己随便定义。当然最简单的就是仍然使用0和1。
时间复杂度O(n^2)，空间复杂度O(1)。

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        if (board.length == 0 || board[0].length == 0) {
            return;
        }
        int row = board.length, col = board[0].length;
        int[] dx = {0, 0, 1, -1, 1, 1, -1, -1};
        int[] dy = {1, -1, 0, 0, 1, -1, 1, -1};
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                int count=0;
                for (int index=0; index<8; index++) {
                    int x = i+dx[index];
                    int y = j+dy[index];
                    if (x<0 || x>= row || y<0 || y>= col) {
                        continue;
                    }
                    count += board[x][y] & 1;
                }
                if ((board[i][j] & 1) >0) {
                    if (count >=2 && count <= 3) {
                        board[i][j] = 0b11;
                    }
                } else if (count == 3) {
                    board[i][j] = 0b10;
                }
            }
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                board[i][j] >>=1;
            }
        }
    }
}
```