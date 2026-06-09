class Solution {
    public boolean isValidSudoku(char[][] board) {
        if(board == null)
            return false;
        if(board.length !=9)
            return false;
        for(int i=0;i<9;i++){
            HashSet<Character>  rows = new HashSet<>();
            HashSet<Character>  columns = new HashSet<>();
            HashSet<Character>  boxes = new HashSet<>();
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'&&!rows.add(board[i][j]))return false;
                if(board[j][i]!='.'&&!columns.add(board[j][i]))return false;
                if(board[i/3*3+j/3][(i%3)*3+j%3]!='.'&&!boxes.add(board[i/3*3+j/3][(i%3)*3+j%3]))return false;
            }
        }
        return true;
    }
}