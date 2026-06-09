### 解题思路
此处撰写解题思路

### 代码

```java
class TicTacToe {

    /** Initialize your data structure here. */
    static char[][] toe;
    // static HashMap<Integer,Integer>player1RowMap=new HashMap<>();
    // static HashMap<Integer,Integer>player1ColMap=new HashMap<>();
    // HashMap<Integer,Integer>player2RowMap=new HashMap<>();
    // HashMap<Integer,Integer>player2ColMap=new HashMap<>();

    public TicTacToe(int n) {
      toe=new char[n][n];
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        if(player!=1&&player!=2){
            return 0;
        }
        if(player==1){
            toe[row][col]='X';
           if(solved(toe,row,col,'X')){
               return 1;
           }else{
               return 0;
           }
        }
        else{
            toe[row][col]='O';
            if(solved(toe,row,col,'O')){
                return 2;
            }else{
                return 0;
            }
        }
    }


   public boolean solved(char[][] toe,int row,int col,char cg){

     //同一行是否满足获胜的要求
     int j=0;
     int n=toe.length;
     boolean isRow=true;
     while(j<n){
         if(toe[row][j]==cg){
             j++;
         }else{
               isRow=false;
               break;
         }
     }
     if(isRow){
         return true;
     }


     //同一列是否满足要求
     boolean isCol=true;
     int k=0;
      while(k<n){
         if(toe[k][col]==cg){
             k++;
         }else{
               isCol=false;
               break;
         }
     }
     if(isCol){
         return true;
     }

// 主对角线是否满足要求
     boolean isLeftUpToRigthDown=true;
     int rs1=0;
     int rc1=0;
     while(rs1<n&&rc1<n){
         if(toe[rs1][rc1]==cg){
             rs1++;
             rc1++;
         }else{
             isLeftUpToRigthDown=false;
             break;
         }
     }
     if(isLeftUpToRigthDown){
         return true;
     }
     //副对角线是否满足要求
boolean isLeftDownToRightUp=true;
     int rs2=n-1;
     int rc2=0;
     while(rs2>=0&&rc2<n){

         if(toe[rs2][rc2]==cg){
             rs2--;
             rc2++;
         }else{
             isLeftDownToRightUp=false;
             break;
         }
     }
     if(isLeftDownToRightUp){
         return true;
     }
     return false;
 }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
```