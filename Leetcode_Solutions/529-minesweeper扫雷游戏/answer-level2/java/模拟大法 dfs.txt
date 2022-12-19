思路：完全按照题目要求的模拟一遍即可
注意点：
递归结束的条件：1、遇见地雷（board[i][j]=='M'）; 2、周围八个点存在地雷（这个地方统计周围八个点地雷的数量统计的应当是未挖出的地雷的数量）
进入递归的条件：周围八个点不存在地雷并且当前要处理的这个点没有被处理过也就是board[i][j]=='E'
```
class Solution {

    private int row;

    private int col;

    private int[][] directions = new int[][]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    public char[][] updateBoard(char[][] board, int[] click) {
        row = board.length;
        col = board[0].length;
        dfs(board, click[0], click[1]);
        return board;
    }

    private void dfs(char[][] board, int i, int j) {
        // 如果是地雷游戏结束
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return;
        }
        // 统计周围八个点地雷的数量
        int count = counter(board, i, j);
        // 如果大于0 说明当前点周围八个方向存在地雷 将当前点置为地雷的数量然后返回
        if (count > 0) {
            board[i][j] = (char) (count + '0');
            return;
        }
        // 到这里说明当前点周围八个点不存在地雷，那么递归的揭露周围八个点
        board[i][j] = 'B';
        for (int[] direction : directions) {
            int x = i + direction[0];
            int y = j + direction[1];
            // 注意这个地方进入递归的条件，周围八个点没有被处理过的才可以去处理（也就是没有被挖出的空方快）
            if (verify(x, y) && board[x][y] == 'E') {
                dfs(board, x, y);
            }
        }
    }

    // 用来检查数组角标越界
    private boolean verify(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    // 计算当前位置周围八个点未挖出的地雷的数量
    private int counter(char[][] board, int i, int j) {
        int count = 0;
        for (int[] direction : directions) {
            int x = i + direction[0];
            int y = j + direction[1];
            if (verify(x, y) && board[x][y] == 'M') {
                count++;
            }
        }
        return count;
    }
}
```
