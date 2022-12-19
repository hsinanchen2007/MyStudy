public int[][] boarder = {{-1,-1},{-1,0},{-1,1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};
    public void gameOfLife(int[][] board) {
//        int[][] res = new int[board.length][board[0].length];
        for(int i = 0;i<board.length;i++){
            for(int j = 0;j<board[0].length;j++){
                int t = servive(i, j, board);
                if(board[i][j] == 1){
                    if(t < 2 || t > 3){
                        board[i][j] = 2;
                    }
                }else{
                    if(t == 3){
                        board[i][j] = 3;
                    }
                }
            }
        }
        for(int i = 0;i<board.length;i++){
            for(int j = 0;j<board[0].length;j++){
                board[i][j] = (board[i][j]&1) == 1?1:0;
            }
        }
    }
    public int servive(int i, int j, int[][] board){
        int res = 0;
        for(int p = 0;p<boarder.length;p++){
            res += judge(i+boarder[p][0],j+boarder[p][1],board);
        }
        return res;
    }
    public int judge(int i, int j, int[][] board){
        return (i<0||j<0||i>=board.length||j>=board[0].length||board[i][j]==0||board[i][j] == 3)?0:1;
    }