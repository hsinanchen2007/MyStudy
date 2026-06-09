### 解题思路
这个题目要把被X包围的O变成X，我们可以换个思路，把不需要改变的O的位置找出来
得到位置后，把一个全部是X的数组中的这些位置变成O就可以了

### 代码

```java
class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        int row = board.length;
        int col = board[0].length;
        // 保存不需要变化的O的坐标
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1) {
                    if (board[i][j] == 'O') {
                        solveDfs(i, j, board, list);
                    }
                }
            }
        }
        // 构建全是X的数组
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                board[i][j] = 'X';
            }
        }
        // 将边缘位置的O复原
        for (Integer index : list) {
            int x = index / col;
            int y = index % col;
            board[x][y] = 'O';
        }
    }

    private void solveDfs(int x, int y, char[][] board, List<Integer> list) {
        if (isValidArea(x, y, board.length, board[0].length) && board[x][y] == 'O') {
            list.add(convertIndex(x, y, board[0].length));
            board[x][y] = 'X';
            solveDfs(x - 1, y, board, list);
            solveDfs(x + 1, y, board, list);
            solveDfs(x, y - 1, board, list);
            solveDfs(x, y + 1, board, list);
        }
    }
    private boolean isValidArea(int x, int y, int row, int col) {
        return x >= 0 && x < row && y >= 0 && y < col;
    }

    private int convertIndex(int x, int y, int length) {
        return x * length + y;
    }
}
```