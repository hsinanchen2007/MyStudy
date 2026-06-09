找到“R”的位置，上下左右扫一下就行

```
    public int numRookCaptures(char[][] board) {
        if (board == null || board.length == 0 || board[0].length == 0) {
            return 0;
        }
        int[] pos = new int[2];
        for (int i = 0; i < board.length; i++) {
            boolean found = false;
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    pos[0] = i;
                    pos[1] = j;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        int res = 0;
        for (int i = pos[0]; i >= 0; i--) {
            if (board[i][pos[1]] == 'B') {
                break;
            } else if (board[i][pos[1]] == 'p') {
                res++;
                break;
            }
        }
        for (int i = pos[0]; i < board.length; i++) {
            if (board[i][pos[1]] == 'B') {
                break;
            } else if (board[i][pos[1]] == 'p') {
                res++;
                break;
            }
        }
        for (int j = pos[1]; j >= 0; j--) {
            if (board[pos[0]][j] == 'B') {
                break;
            } else if (board[pos[0]][j] == 'p') {
                res++;
                break;
            }
        }
        for (int j = pos[1]; j < board[0].length; j++) {
            if (board[pos[0]][j] == 'B') {
                break;
            } else if (board[pos[0]][j] == 'p') {
                res++;
                break;
            }
        }
        return res;

    }
```