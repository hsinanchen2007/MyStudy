```java
class Solution {
    public void solve(char[][] board) {
        int m = board.length;
        if (m == 0) return;
        int n = board[0].length;

        boolean[][] visited = new boolean[m][n];
        int[][] dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        Set<String> set = new HashSet<>();
        Queue<int[]> queue = new LinkedList<>();
        // 将边界中的字符 O 都放入到队列中
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                queue.add(new int[]{i, 0});
            }
            if (board[i][n - 1] == 'O') {
                queue.add(new int[]{i, n - 1});
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                queue.add(new int[]{0, i});
            }
            if (board[m - 1][i] == 'O') {
                queue.add(new int[]{m - 1, i});
            }
        }

        // 从边界中的字符 O 开始广度搜索，搜索到的字符 O 都不能变成字符 X
        while (!queue.isEmpty()) {
            int[] currEle = queue.poll();
            int currRow = currEle[0];
            int currCol = currEle[1];
            set.add(currRow + "$" + currCol);
            visited[currRow][currCol] = true;
            for (int[] dir : dirs) {
                int row = currRow + dir[0];
                int col = currCol + dir[1];
                if (row >= 0 && row < m && col >= 0 && col < n
                    && !visited[row][col] && board[row][col] == 'O') {
                    set.add(row + "$" + col);
                    queue.add(new int[]{row, col});
                }
            }
        }

        // 将需要变成字符 X 的字符 O 变成字符 X
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'O' && !set.contains(i + "$" + j)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
}
```