做出来了，但还是效率不太好，可读性还不好。。。加油┗|｀O′|┛ 嗷~~
```
    public boolean exist(char[][] board, String word) {
        int h = board.length, w = 0;
        if (h > 0) w = board[0].length;
        boolean[][] visited = new boolean[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == word.charAt(0)) {
                    visited[i][j] = true;
                    if (exist(board, i, j, 1, word, visited)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    private boolean exist(char[][] board, int i, int j, int ind, String word, boolean[][] visited) {
        if (ind == word.length()) return true;
        //上、下、左、右
        int[][] go = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        boolean a = false, b = false, c = false, d = false;

        //比较上一个字符和word的字符是否匹配
        if (i > 0 && board[i + go[0][0]][j + go[0][1]] == word.charAt(ind) && !visited[i + go[0][0]][j + go[0][1]]) {
            visited[i + go[0][0]][j + go[0][1]] = true;
            a = exist(board, i + go[0][0], j + go[0][1], ind + 1, word, visited);
            if (a) return a;
        }
//比较下一个字符和word的字符是否匹配
        if (i < board.length - 1 && board[i + go[1][0]][j + go[1][1]] == word.charAt(ind) && !visited[i + go[1][0]][j + go[1][1]]) {
            visited[i + go[1][0]][j + go[1][1]] = true;
            b = exist(board, i + go[1][0], j + go[1][1], ind + 1, word, visited);
            if (b) return b;
        }
//比较左一个字符和word的字符是否匹配
        if (j > 0 && board[i + go[2][0]][j + go[2][1]] == word.charAt(ind) && !visited[i + go[2][0]][j + go[2][1]]) {
            visited[i + go[2][0]][j + go[2][1]] = true;
            c = exist(board, i + go[2][0], j + go[2][1], ind + 1, word, visited);
            if (c) return c;
        }
//比较右一个字符和word的字符是否匹配
        if (j < board[0].length - 1 && board[i + go[3][0]][j + go[3][1]] == word.charAt(ind) && !visited[i + go[3][0]][j + go[3][1]]) {
            visited[i + go[3][0]][j + go[3][1]] = true;
            d = exist(board, i + go[3][0], j + go[3][1], ind + 1, word, visited);
            if (d) return d;
        }
        visited[i][j] = false;
        return false;
    }
```
