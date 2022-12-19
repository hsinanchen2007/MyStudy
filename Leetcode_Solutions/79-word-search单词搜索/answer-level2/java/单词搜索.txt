从四个方向DFS搜索，注意记录下走过的路径
```
    private boolean[][] isUsed;
    public boolean exist(char[][] board, String word) {
        int row = board.length;
        if(row == 0) return false;
        int col = board[0].length;
        isUsed = new boolean[row][col];
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(solve(i, j, 0, board, word.toCharArray())) return true;
        
        return false;
    }
    
    private boolean solve(int x, int y,int index, char[][] board, char[] arr){
        if(x < 0 || x >= board.length || y < 0 || y >= board[0].length || isUsed[x][y]) return false;
        if(board[x][y] != arr[index]) return false;
        if(index == arr.length-1) return true;
        
        int[][] dir = {{1, 0}, {0,-1}, {-1, 0}, {0, 1}};
        isUsed[x][y] = true;
        for(int i=0; i<4; i++){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(solve(dx, dy, index+1, board, arr)) return true; 
        }
        isUsed[x][y] = false;
        
        return false;
    }
```
