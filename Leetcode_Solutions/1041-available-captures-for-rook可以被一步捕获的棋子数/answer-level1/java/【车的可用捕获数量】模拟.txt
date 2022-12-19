### 解题思路
又是一道模拟题，先找到白车的位置，然后按四个方向移动，碰到黑卒、白象、边界就停止，记录移动过程中碰到的黑卒数量。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int checkerboardSize = board.length;
        int rX = 0, rY = 0; // 记录白车的位置
        // 找到白车的位置
        for (int i = 0; i < checkerboardSize; i++) {
            for (int j = 0; j < checkerboardSize; j++) {
                if (board[i][j] == 'R') {
                    rX = i;
                    rY = j;
                    break;
                }
            }
        }

        int ans = 0;
        // 按四个方向移动，碰到黑卒或者白象或者边界就停止
        int[][] move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < move.length; i++) {
            int currX = rX, currY = rY;
            while (true) {
                currX += move[i][0];
                currY += move[i][1];
                // 碰到边界或者白象
                if (currX < 0 || currX >= checkerboardSize || currY < 0 || currY >= checkerboardSize || board[currX][currY] == 'B') {
                    break;
                }
                // 碰到黑卒
                if (board[currX][currY] == 'p') {
                    ans++;
                    break;
                }
            }
        }
        return ans;

    }
}
```