### 解题思路
二维数组映射为一维数组处理，注意控制越界访问

### 代码

```java
class Solution {
    int m , n;
    int[] cellList = null;
    /**
    * 1. 遍历二维数组，将其映射为一维数组
    * 2. 再遍历二维数组，根据四条生存定律去判断当前细胞的下一次状态，并更新
    **/
    public void gameOfLife(int[][] board) {
        m = board.length; n = board[0].length;
        cellList = new int[m * n];
        for (int i = 0; i < board.length; i++){
            for ( int j = 0; j < board[i].length; j++){
                cellList[i * n + j] = board[i][j];
            }
        }
        // for (int i = 0; i < cellList.length; i ++){
        //     System.out.print(cellList[i]);
        // }
        // System.out.println();

        for (int i = 0; i < board.length; i++){
            for ( int j = 0; j < board[i].length; j++){
                board[i][j] = setCell(i,j);
                // System.out.print(board[i][j]);
            }
            // System.out.println("");
        }
    }

    public int setCell(int i, int j){
         //获取8个位置的活细胞数量
        int liveCount = 0;
        liveCount = checkStatus((i + 1) * n + j) ? liveCount+1 : liveCount;
        liveCount = checkStatus((i - 1) * n + j) ? liveCount+1 : liveCount;
        //防止左侧和右侧的越界访问
        if ((j - 1) >= 0) {
            liveCount = checkStatus(i * n + j - 1) ? liveCount+1 : liveCount;
            liveCount = checkStatus((i - 1) * n + j - 1) ? liveCount+1 : liveCount;
            liveCount = checkStatus((i + 1) * n + j - 1) ? liveCount+1 : liveCount;
        }
        if ((j + 1) < n) {
            liveCount = checkStatus(i * n + j + 1) ? liveCount+1 : liveCount;
            liveCount = checkStatus((i - 1) * n + j + 1) ? liveCount+1 : liveCount;
            liveCount = checkStatus((i + 1) * n + j + 1) ? liveCount+1 : liveCount;
        }

        //执行4条逻辑判断
        if (checkStatus(i * n + j)){
            return (liveCount < 2 || liveCount > 3) ? 0 : 1;
        } else if (liveCount == 3){
            return 1;
        } else {
            return 0;
        }
        
    }
    public boolean checkStatus(int index){
        if (index < 0 || index >= cellList.length){
            return false;
        }

        return cellList[index] == 1;
    }
}
```