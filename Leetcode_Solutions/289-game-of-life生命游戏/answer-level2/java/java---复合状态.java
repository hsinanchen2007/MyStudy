```
    /**
    * 原地修改，需要使用特殊的数记录复合状态
    * 规则1： -1 活细胞-->死细胞
    * 规则2： 1 活细胞-->活细胞
    * 规则3： -1 死细胞-->死细胞
    * 规则4： 2 死细胞-->活细胞
    */
    public void gameOfLife(int[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = nextStatus(board, i, j);
            }
        }
        // 将2替换为1， -1替换为0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }        
    }

    int[] row = {-1, -1, -1, 0, 0, 1, 1, 1};
    int[] col = {-1, 0, 1, -1, 1, -1, 0, 1};

    private int nextStatus(int[][] board, int i, int j) {
        int status = board[i][j];
        int liveNum = 0;
        for (int k = 0; k < 8; k++) {
            int r = i + row[k], c = j + col[k];
            if (r >= 0 && r < board.length &&
                c >= 0 && c < board[0].length &&
                (board[r][c] == 1 || board[r][c] == -1)) {
                liveNum++;
            }
        }
        if (status == 1 && (liveNum < 2 || liveNum > 3)) {
            return -1;
        } else if (status == 1 && (liveNum == 2 || liveNum == 3)) {
            return 1;
        } else if (status == 0 && liveNum == 3) {
            return 2;
        }
        return status;
    }
```