### 解题思路
![image.png](https://pic.leetcode-cn.com/281d9a42e3b7a41ebf2d1bd067c72fbb26d51d54b6b120ee89fc05dbcd86e201-image.png)

如果每次在下完棋子之后都去遍历矩阵，时间复杂度会很高，想了一下用几个数组记录之前下的棋子。
raws[]：raws[i]代表第i行之前下过的棋子，如果既存在X又存在O，则为-1；
cols[]: cols[i]代表第i列之前下过的棋子，如果既存在X又存在O，则为-1；
dias[]: dias[0]代表从[0，0]到[n,n]的对角线上下过的棋子，如果即存在X又存在O,则为-1.

raw[i]%'O'!=0 代表该行之前被下过'X'.

### 代码

```java
class TicTacToe {

    char[][] mat;
    int raws[];
    int cols[];
    int dias[];


    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        mat = new char[n][n];
        raws = new int[n];
        cols = new int[n];
        dias = new int[2];
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
        char syb = player == 1? 'X':'O';
        mat[row][col] = syb;
        if(row==col&&dias[0]!=-1){
            dias[0] += syb;
            if(dias[0]%syb!=0){
                dias[0]=-1;
            }else if(dias[0]/syb==mat.length){
                return player;
            }
        }
        if(row+col==mat.length-1&&dias[1]!=-1){
            dias[1] += syb;
            if(dias[1]%syb!=0){
                dias[1]=-1;
            }else if(dias[1]/syb==mat.length){
                return player;
            }
        }
        if(cols[col]!=-1){
            cols[col] += syb;
            if(cols[col]%syb!=0){
                cols[col]=-1;
            }else if(cols[col]/syb==mat.length){
                return player;
            }
        }
        if(raws[row]!=-1){
            raws[row] += syb;
            if(raws[row]%syb!=0){
                raws[row]=-1;
            }else if(raws[row]/syb==mat.length){
                return player;
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