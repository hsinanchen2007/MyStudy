
回溯算法的三要素
1. 路径：已经做出的选择
2. 选择列表：当前可以做出的选择
3. 结束条件：到达决策树底层，无法再做出选择


N皇后剪枝条件：当前board[row][col]列上是否已经有皇后；board[row][col]左上对线是否已经有皇后；board[row][col]右上对线是否有皇后。



```
 public List<List<String>> solveNQueens(int n) {

        List<List<String>> res = new ArrayList<>();//结果

        //定义一个N^N 的二维数组
        String[][] board = this.init(n);

        //回溯
        backtrack(n,0,board,res);

        return res;
    }

    /**
     * 回溯
     * @param n
     * @param row
     * @param board
     * @param res
     */
    private void backtrack(int n ,int row,String[][] board,List<List<String>> res){

        //结束条件：当 row = n
        if(row == n){
            res.add(this.track(board,n));
            return;
        }

        for(int i = 0; i < n;i++){

            //剪枝：当前 board[row][i] 不满足条件
            if(!isUsable(row,i,board)) continue;

            //做出选择
            board[row][i] = "Q";

            //做下一层决策
            backtrack(n,row + 1,board,res);

            //取消选择,还原
            board[row][i] = ".";

        }

    }

    /**
     * 初始化
     * @param n
     * @return
     */
    private String[][] init(int n){
        String[][] board = new String[n][n];//N x N大小的棋盘
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[i].length;j++){
                board[i][j] = ".";
            }
        }
        return board;
    }

    /**
     * 检查是否符合规则
     * @param row
     * @param col
     * @param board
     * @return
     */
    private boolean isUsable(int row,int col,String[][] board){

        int n = board.length;

        //检查列
        for(int i = 0; i < n;i++){
            if(board[i][col] == "Q") return false;
        }

        //检查对线 (小于 row/col的范围) 左上部分
        for(int i = row-1,j = col-1; i >= 0 && j >= 0 ;i--,j--) {
            if(board[i][j] == "Q") return false;
        }

        //检查对线 (小于 row/大于col的范围) 右上部分
        for(int i = row-1,j = col+1; i >= 0 && j < n; i--,j++) {
            if(board[i][j] == "Q") return false;
        }

        return true;
    }


    /**
     * 将int类型棋盘转换成输出格式
     */
    private List<String> track(String[][] board, int n) {
        List<String> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder temp = new StringBuilder();
            for (int j = 0; j < n; j++) {
                temp.append(board[i][j]);
            }
            list.add(temp.toString());
        }
        return list;
    }
```
