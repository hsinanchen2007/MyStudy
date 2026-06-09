### 解题思路
此处撰写解题思路
每放入一个仅仅影响该行 该列 或者该位置所在对角线，可能从不满足要求变为满足要求
### 代码

```java
class TicTacToe {

    int[][] aa ;
    int n ;
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        this.aa = new int[n][n];
        this.n = n;
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
        aa[row][col] = player;
        // 行满足要求
        for(int i=0; i<n; i++){
            if(aa[row][i] == player){
                if(i == n-1){
                    return player;
                }
            }else{
                break;
            }
        }
        // 列满足要求
        for(int i=0; i<n; i++){
            if(aa[i][col] == player){
                if(i == n-1){
                    return player;
                }
            }else{
                break;
            }
        }
        // 左下满足要求
        if(row == col){
            for(int i=0; i<n ; i++){
                if(aa[i][i] == player){
                    if(i == n-1){
                     return player;
                    }
                }else{
                    break;
                }
            }
        }

        // 左上满足要求
        if(row + col == n-1){
            for(int i=0; i<n ; i++){
                if(aa[n-i-1][i] == player){
                    if(i == n-1){
                     return player;
                    }
                }else{
                    break;
                }
            }
        }


        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
```