空间换时间
```
    public boolean isValidSudoku(char[][] board) {
        int[][] rows = new int[9][9]; 
        int[][] cols = new int[9][9]; 
        int[][] mat  = new int[9][9];
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                rows[i][val] ++;
                cols[j][val] ++;
                mat[j / 3 + 3 * (i/3)][val] ++;
                
                if(rows[i][val]  > 1 || cols[j][val] > 1 || mat[j / 3 + 3 * (i/3)][val] > 1) return false;    
            }
        }
        
        return true;
    }
```
