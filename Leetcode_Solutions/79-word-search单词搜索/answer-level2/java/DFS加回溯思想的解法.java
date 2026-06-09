```java
class Solution {
    // DFS
    public boolean exist(char[][] board, String word) {
        if (word == null || word.length() == 0) return false;

        int m = board.length;
        int n = board[0].length;

        if (word.length() > m * n) return false;

        boolean[][] visited = new boolean[m][n];
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[0].length; col++) {
                // 从第一个等于 word 首字符的元素开始深度优先搜索
                if (board[row][col] == word.charAt(0) 
                    && dfs(board, word, visited, 0, row, col)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean dfs(char[][] board, 
                        String word, 
                        boolean[][] visited, 
                        int index, int row, int col) {
        // 已经匹配到了字符串 word 的最后一个字符
        if (index == word.length()) return true;
        
        // 不符合边界条件
        if (row < 0 || row >= board.length 
            || col < 0 || col >= board[0].length
            || visited[row][col] || word.charAt(index) != board[row][col]) {
            return false;
        }

        // 标记当前元素已经被访问
        visited[row][col] = true;

        // 从当前字符的上下左右进行深度优先搜索
        if (dfs(board, word, visited, index + 1, row - 1, col)
            || dfs(board, word, visited, index + 1, row + 1, col)
            || dfs(board, word, visited, index + 1, row, col - 1)
            || dfs(board, word, visited, index + 1, row, col + 1)) {
            return true;
        }

        // 重置，因为当前的元素可能被其他的路径选择
        // 这里用的是回溯的思想
        visited[row][col] = false;
        return false;
    }
}
```