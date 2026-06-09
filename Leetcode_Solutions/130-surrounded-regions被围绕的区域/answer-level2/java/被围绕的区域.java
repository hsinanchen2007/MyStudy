DFS
```
   private int[][] temp;
    public void solve(char[][] board) {
        int row = board.length;
        if(row == 0) return; 
        int col = board[0].length;
        temp = new int[row][col];
        
        for(int i=0; i<col; i++){
            solve(0, i, board);
            solve(row-1, i, board);
        }
        
        for(int i=1; i<row-1; i++){
            solve(i, 0, board);
            solve(i, col-1 , board);
        }
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++){
                if(temp[i][j] == 1)
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }  
    }
    
    private void solve(int x, int y, char[][] arr){
        if(arr[x][y] != 'O' || temp[x][y] == 1){
            return;
        }
        temp[x][y] = 1;
        int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int row = x + dx[i];
            int col = y + dy[i];
            if(row >= 0 && row < arr.length && col >=0 && col < arr[0].length){
                solve(row, col, arr);
            }
        }
        
    }
```
