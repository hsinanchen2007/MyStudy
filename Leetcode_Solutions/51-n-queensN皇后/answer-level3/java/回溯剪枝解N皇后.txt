**暴力枚举:** 枚举每一层皇后能在的所有可能性
**剪枝:** 根据条件每列、每个左右斜列只有一个皇后的条件
```
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> results = new LinkedList<>();
        char[][] board = new char[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(board[i], '.');
        }
        dfs(board, 0, results, new HashSet<>(), new HashSet<>(), new HashSet<>());
        return results;
    }

    private void dfs(char[][] board, int curRow, List<List<String>> results,
                     Set<Integer> cols, Set<Integer> lb, Set<Integer> rb) {
        if (curRow == board.length) {
            addResult(board, results);
            return;
        }
        for (int i = 0; i < board.length; ++i) {
            if (!cols.contains(i) && !lb.contains(curRow + i) && !rb.contains(curRow - i)) {
                cols.add(i);lb.add(curRow + i);rb.add(curRow - i);
                board[curRow][i] = 'Q';
                dfs(board, curRow + 1, results, cols, lb, rb);
                board[curRow][i] = '.';
                cols.remove(i);lb.remove(curRow + i);rb.remove(curRow - i);
            }
        }
    }

    private void addResult(char[][] board, List<List<String>> results) {
        List<String> result = new LinkedList<>();
        for (int i = 0; i < board.length; ++i) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < board[0].length; ++j) {
                sb.append(board[i][j]);
            }
            result.add(sb.toString());
        }
        results.add(result);
    }
```