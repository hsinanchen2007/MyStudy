想法很简单  把要修改的（0->1,1->0）加2  后面用的时候视作mod2的值，二次遍历大于1的都+1%2

class Solution {
    public void gameOfLife(int[][] board) {
        for(int i=0;i<board.length;i++){
            for(int j = 0;j<board[i].length;j++){
                getNext(i,j,board);
            }
        }
        for(int i=0;i<board.length;i++){
            for(int j = 0;j<board[i].length;j++){
                if (board[i][j] >= 2)
                board[i][j] = (board[i][j]+1)%2;
            }
        }
    }

    private void getNext(int i, int j, int[][] board){
        int live = 0;
        if(i>0){
            if(j>0){
                live+=board[i-1][j-1]%2;
            }
            if(j<board[i-1].length-1){
                live+=board[i-1][j+1]%2;
            }
            live+=board[i-1][j]%2;
        }
        if(i<board.length-1){
            if(j>0){
                live+=board[i+1][j-1]%2;
            }
            if(j<board[i+1].length-1){
                live+=board[i+1][j+1]%2;
            }
            live+=board[i+1][j]%2;
        }
        if(j>0){
            live+=board[i][j-1]%2;
        }
        if(j<board[i].length-1){
            live+=board[i][j+1]%2;
        }
        if(board[i][j] == 0 && live == 3){
            board[i][j]+=2;
        } else if(board[i][j] == 1 && (live > 3 || live<2)){
            board[i][j]+=2;
        }
    }
}