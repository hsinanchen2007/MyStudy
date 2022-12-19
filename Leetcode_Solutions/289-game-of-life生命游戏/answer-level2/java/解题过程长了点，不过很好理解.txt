内容长了点，不过很好理解。

```
public static void gameOfLife(int[][] board) {
        int[][] boardOld = new int[board.length][board[0].length];
        //复制一个数组，记录数组的当前状态
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                boardOld[i][j] = board[i][j];
            }
        }
        //对数组进行更新
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = update(boardOld,i,j);
            }
        }
    }

    /**
     * 
     */
    public static int update(int[][] board, int x,int y){
        int currentCellStauts = board[x][y];//读取当前细胞状态，时的还是活的
        int liveCellsArountCurrentCell = countAlive(board,x,y);//当前细胞周围活细胞数量
        //根据游戏规则，返回相应的值
        //活细胞
        if(currentCellStauts==1){
            if(liveCellsArountCurrentCell<2)return 0;
            else if(liveCellsArountCurrentCell==2||liveCellsArountCurrentCell==3)return 1;
            else {
                return 0;
            }
        }else{
            if (liveCellsArountCurrentCell==3)return 1;
            else return 0;
        }
    }

    /**
    * 当前细胞周围活的细胞数量
    * */
    public static int countAlive(int[][] board, int x, int y){
        return isAlive(x-1,y-1,board)+isAlive(x-1,y,board)+isAlive(x-1,y+1,board)
                +isAlive(x,y-1,board)+isAlive(x,y+1,board)
                +isAlive(x+1,y-1,board)+isAlive(x+1,y,board)+isAlive(x+1,y+1,board);
    }

    /**
     * 返回board[x][y]是否存活，越界返回0，视为死亡
     * */
    private static int isAlive(int x, int y, int[][] board) {
        int m = board.length-1,n = board[0].length-1;
        if (x < 0 || x > m) return 0;
        if (y < 0 || y > n) return 0;
        return board[x][y];
    }
```