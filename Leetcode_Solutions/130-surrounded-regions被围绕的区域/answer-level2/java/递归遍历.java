初始化数组boolean[] b，映射二维数组char[][] board, b[k]对应board[k/w][k%w]，其中w为board的宽度；
从边界出发，发现O时，设置对应的b[k]为true；最后遍历b，值为true的设置为O，其余为X。
```
class Solution {
    public void solve(char[][] board) {
        int h = board.length;
        if (h == 0) return;
        int w = board[0].length;
        if (w == 0) return;
        int size = h * w;
        boolean[] b = new boolean[size];    // b映射board, 初始时都为false
        for (int i = 0; i < w; i++) {
            setTrue(i, w, board, b);    // 第一行
            setTrue((h-1) * w + i, w, board, b);    // 最后一行
        }
        for (int j = 0; j < h; j++) {
            setTrue(j * w, w, board, b);    // 第一列
            setTrue(j * w + w - 1, w, board, b);    // 最后一列
        }
        for (int t = 0; t < b.length; t++) {
            if (!b[t] && board[t/w][t%w] == 'O') {  // 设置b[t]==false并且board[t/w][t%w]=='0'的为X
                board[t/w][t%w] = 'X';
            }
        }
    }

    public void setTrue(int k, int w, char[][] board, boolean[] b) {
        // 递归遍历
        if (!b[k] && board[k/w][k%w] == 'O') {
            b[k] = true;
            if (k + w < b.length && !b[k + w]) {
                setTrue(k + w, w, board, b);
            }
            if (k - w >= 0 && !b[k - w]) {
                setTrue(k - w, w, board, b);
            }
            if (k % w > 0 && !b[k - 1]) {
                setTrue(k - 1, w, board, b);
            }
            if ((k + 1) % w > 0 && !b[k + 1]) {
                setTrue(k + 1, w, board, b);
            }
        }
    }
}
```