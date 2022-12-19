class Solution {
    private final static char ship='X';
    public int countBattleships(char[][] board) {
         
        int m=board.length;
        int n=board[0].length;
        int[][] visit=new int[m][n];
        int count=0;
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(board[i][j]==ship ){
                   if(visit[i][j]==0){
                       count++;
                   }
                   if(i+1<m && board[i+1][j]==ship ){
                       visit[i+1][j]=1;
                   }
                   if(j+1<n && board[i][j+1]==ship){
                       visit[i][j+1]=1;
                   }
               }
            }
        }
        return count;
    
    }
}