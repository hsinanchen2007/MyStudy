### 解题思路
判断当前落子所在行与列是否都是该棋手的子，以及如果落子在对角线上,则同时需要判断对角线上的子是否都是该棋手的子。

### 代码

```java
class TicTacToe {
    private int[][] data;
    
    public TicTacToe(int n) {
        data = new int[n][n];
    }
    
    public int move(int row, int col, int player) {
        data[row][col] = player;
        for(int i = 0; i < data.length; i++){
            if(data[i][col] != player){
               break;
            }
            if(i == data.length - 1){
                return player;
            }
        }
        for(int j = 0; j < data.length; j++){
            if(data[row][j] != player){
               break;
            }
            if(j == data.length - 1){
                return player;
            }
        }
        if(row == col){
            for(int i = 0; i < data.length; i++){
                if(data[i][i] != player){
                   break;
                }
                if(i == data.length - 1){
                    return player;
                }
            }
        }
        if(row + col == data.length - 1){
            for(int i = 0; i < data.length; i++){
                if(data[i][data.length-1-i] != player){
                   break;
                }
                if(i == data.length - 1){
                    return player;
                }
            }
        }
        return 0;
    }
}

```