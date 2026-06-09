置二维数组当前元素为非字母类型的任意字符，表示当前查找过程中已经走过，不再重走。回溯时置回原字符。

    public boolean exist(char[][] board, String word) {
        if(board.length == 0) return false;
        for(int i = 0; i < board.length; i++){
            for(int j = 0 ; j < board[0].length; j++){
                if(dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int index, int x, int y){
        if(x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != word.charAt(index)){
            return false;
        }
        if(index == word.length() - 1){
            return true;
        }
        char origin = board[x][y];
        board[x][y] = '1';

        boolean res = dfs(board, word, index + 1, x + 1, y) ||
        dfs(board, word, index + 1, x , y + 1) ||
        dfs(board, word, index + 1, x , y - 1) ||
        dfs(board, word, index + 1, x - 1 , y);

        board[x][y] = origin;

        return res;
    }
