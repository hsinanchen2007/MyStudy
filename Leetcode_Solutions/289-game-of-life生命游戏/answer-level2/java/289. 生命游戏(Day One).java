### 解题思路
一个 int 有 32 bit，输入数据只用了其中一个 bit，所以我们可以利用其他空闲的bit位进行“原地修改”。
### 代码

```java
class Solution {
void gameOfLife(int[][] board) {
        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};

        for (int i = 0; i < board.length; i++) {
            for (int j = 0 ; j < board[i].length; j++) {
                int sum = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length) {
                        sum += (board[nx][ny] & 1); // 只累加最低位
                    }
                }
                if (board[i][j] == 1) {
                    if(sum == 2 || sum == 3) {
                        board[i][j] |= 2;  // 使用第二个bit标记是否存活
                    }
                } else {
                    if (sum == 3) {
                        board[i][j] |= 2; // 使用第二个bit标记是否存活
                    }
                }
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                board[i][j] >>= 1; //右移1位，用第二bit覆盖第一个bit。
            }
        }
    }
}
```