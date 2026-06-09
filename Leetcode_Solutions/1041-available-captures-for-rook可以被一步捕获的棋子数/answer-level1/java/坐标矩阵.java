### 解题思路
1、坐标矩阵
2、遇到非空格就停下来，判断是否能吃掉

### 代码

```java
class Solution {
    private int x;
    private int y;
    private int result;
    public int numRookCaptures(char[][] board) {
        int[] xDirect = {0, 0, 1, -1};
        int[] yDirect = {1, -1, 0, 0};

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            runOneWay(board, xDirect[i], yDirect[i]);
        }
        return result;
    }

    private void runOneWay(char[][] board, int xDirect, int yDirect) {
        int tmpX = x;
        int tmpY = y;
        while (true) {
            tmpX += xDirect;
            tmpY += yDirect;
            if (tmpX < 0 || tmpX >= 8 || tmpY < 0 || tmpY >= 8) {
                break;
            }
            if (board[tmpX][tmpY] != '.') {
                if (board[tmpX][tmpY] == 'p') {
                    result++;
                }
                break;
            }
        }
    }
}
```