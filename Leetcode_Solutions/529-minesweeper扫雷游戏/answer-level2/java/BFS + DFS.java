    
```
public char[][] updateBoard(char[][] board, int[] click) {
    int rowLength = board.length;
    int colLength = board[0].length;

    int clickRow = click[0];
    int clickCol = click[1];

    if (board[clickRow][clickCol] == 'M') {
        board[clickRow][clickCol] = 'X';
    } else {
        int count = 0;
        for (int i = -1; i < 2; i ++) {
            for (int j = -1; j < 2; j ++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int row = clickRow + i;
                int col = clickCol + j;

                if (row < 0 || row >= rowLength || col < 0 || col >= colLength) {
                    continue;
                }

                if (board[row][col] == 'M') {
                    count ++;
                }
            }
        }

        if (count > 0) {
            board[clickRow][clickCol] = (char)(count + '0');
        } else {
            board[clickRow][clickCol] = 'B';

            for (int i = -1; i < 2; i ++) {
                for (int j = -1; j < 2; j ++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }

                    int row = clickRow + i;
                    int col = clickCol + j;

                    if (row < 0 || row >= rowLength || col < 0 || col >= colLength) {
                        continue;
                    }

                    if (board[row][col] == 'E') {
                        updateBoard(board, new int[]{row, col});
                    }
                }
            }
        }
    }

    return board;
}
```
