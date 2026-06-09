**方法一：推演结果**

思路：
在"沙盘"中推演每个位置在一次更新后的结果然后记录，直至推演完所有位置。
```
class Solution {
    public void gameOfLife(int[][] board) {
        int lenX = board.length, lenY = board[0].length;
        int[][] temp = new int[lenX][lenY];
        // 方向向量
        int[] dx = {1,1,1,0,-1,-1,-1,0};
        int[] dy = {1,0,-1,-1,-1,0,1,1};
        // 数组属于对象，需要将原数组复制到"沙盘"推演，避免影响之后位置推演。
        for (int i = 0; i < lenX; i++) {
            for (int j = 0; j < lenY; j++) {
                temp[i][j] = board[i][j];
            }
        }
        // 遍历推演每个位置在一次更新后的状态。
        for (int i = 0; i < lenX; i++) {
            for (int j = 0; j < lenY; j++) {
                int cur = temp[i][j];
                int num = 0;
                for (int k = 0; k < 8; k++) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    // 越界判断。
                    if (newX < 0 || newX >= lenX || newY < 0 || newY >= lenY) {
                        continue;
                    }
                    // 记录当前位置周围的活细胞个数。
                    if (temp[newX][newY] == 1) {
                        num++;
                    }
                }
                // 根据四条生存定律推演当前位置在一次更新之后的状态。
                if ((cur == 0 && num == 3) || (cur == 1 && (num == 2 || num == 3))) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
}
```
