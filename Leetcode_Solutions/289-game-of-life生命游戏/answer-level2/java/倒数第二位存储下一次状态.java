
```
        int rows = board.length;
        int cols = board[0].length;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int sum = 0;

                for (int dx = -1; dx < 2; dx++) {
                    for (int dy = -1; dy < 2; dy++) {
                        if (dx != 0 || dy != 0) {
                            int x = row + dx;
                            int y = col + dy;
                            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                                sum += board[x][y] & 1;
                            }
                        }
                    }
                }
                if (sum == 3) {
                    board[row][col] = board[row][col] | 0b10;
                } else if (sum == 2) {
                    board[row][col] = board[row][col] * 3;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }

```