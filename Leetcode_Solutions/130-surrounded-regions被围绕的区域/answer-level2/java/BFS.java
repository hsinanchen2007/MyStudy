 public void solve(char[][] board) {
         //边界判断
         if (board == null || board.length == 0 || board[0].length == 0) {
             return;
         }
         int height = board.length;
         int width = board[0].length;
        for (int col = 0; col < width; col++) {
             if (board[0][col] == 'O') {
                 dfs(0,col,height,width,board);
             }
             if (board[height - 1][col] == 'O') {
                 dfs(height - 1, col,height,width,board);
             }
         }
         for (int row = 0; row < height; row++) {
             if (board[row][0] == 'O') {
                 dfs(row,0,height,width,board);
             }
             if (board[row][width - 1] == 'O') {
                 dfs(row,width - 1,height,width,board);   
             }
         }
         for (int i = 0; i < height; i++) {
             for (int j = 0; j < width; j++) {
                 if (board[i][j] == 'B') {
                     board[i][j] = 'O';
                 } else {
                     board[i][j] = 'X';
                 }
             }
         }  
    }

    public void dfs (int row, int col, int height, int width, char[][] board) {
        if (row < 0 || col < 0 || row >= height || col >= width || board[row][col] != 'O') {
            return;
        }
        board[row][col] = 'B';
        dfs (row - 1, col, height, width, board); //向上搜索
        dfs (row + 1, col, height, width, board); //向下搜索
        dfs (row, col - 1 , height, width, board); //向左搜索
        dfs (row, col + 1, height, width, board); //向右搜索
    }