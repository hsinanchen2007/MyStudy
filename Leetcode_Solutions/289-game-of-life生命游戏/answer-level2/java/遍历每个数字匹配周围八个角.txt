### 解题思路

#### *   通过面向过程的思维去解决问题,遍历每个细胞,然后判断每个细胞八个角落是否存活来觉得这个细胞是否存活*
    
#### 大体流程
    1.创建一个新数组来接收更新后的细胞
    2.获取每个格子上面的细胞数字
    3.再依次判断八个角上是否有存活的数字
    4.最后根据周围存活数量来设置新数组对应位置的数字
#### 主要问题
    1.如何判断细胞在不是在方阵的周围呢?因为周围的话某些角落是不可能有数字的
    2.如何判断对应细胞八个角是否有存活数字?
#### 解决办法
    /**
     * 0 0 0 1
     * 1 0 0 1
     * 0 1 1 0
     * 1 1 1 0
     */
    首先按照 x 和 y 轴去定位每个数字,然后用多个if去判断每个角落是否存在,如果存在是否存活,下面是示例
        survivalNum = 周围存活细胞总数
        // 判断左上角细胞
        if (x > 0 && y > 0 && board[y - 1][x -1] > 0) {
            // 因为 x = 0 和 y = 0 的坐标不可能有左上角,所以直接就过滤了
            // board[y - 1][x -1] 就表示左上角格子的坐标
            survivalNum++;
        }
        // 判断上方细胞
        if (y > 0 && board[y - 1][x] > 0){
            survivalNum++;
        }
        ...
    之后再根据**survivalNum**的数量去判断当前格子细胞是否存活
        if (survivalNum == 3){
            return 1;
        } else if (survivalNum == 2 && present == 1){
            return 1;
        }else {
            return 0;
        }
#### 可能解题思路并不巧妙,不过当时脑子里第一时间就想到了这个,完全是按照自己肉眼去判断是否存活的步骤去写的→_→  

    

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int[][] newBoard = new int[board.length][];
        // 1.遍历每个数组当中的数字
        System.out.println("[");
        for (int i = 0; i < board.length; i++) {
            System.out.print("[");
            int[] subarray = new int[board[i].length];
            for (int i1 = 0; i1 < board[i].length; i1++) {
                // 2.判断该细胞数字是否存活
                subarray[i1] = isSurvive(i1, i, board);
                System.out.print(subarray[i1]);
                if (i1 < board[i].length - 1) {
                    System.out.print(",");
                }
            }
            System.out.print("]");
            if (i < board.length - 1) {
                System.out.print(",");
            }
            System.out.println();
            newBoard[i] = subarray;
        }
        System.arraycopy(newBoard, 0, board, 0, newBoard.length);
        System.out.println("]");
    }
     private int isSurvive(int x, int y, int [][]board){
        int survivalNum = 0;
        int present = board[y][x];
        // 判断左上角细胞
        if (x > 0 && y > 0 && board[y - 1][x -1] > 0) {
            survivalNum++;
        }
        // 判断上方细胞
        if (y > 0 && board[y - 1][x] > 0){
            survivalNum++;
        }
        // 判断右上角细胞
        if (x < board[0].length - 1 && y > 0 && board[y - 1][x + 1] > 0){
            survivalNum++;
        }
        // 判断左侧细胞
        if (x > 0 && board[y][x -1] > 0) {
            survivalNum++;
        }
        // 判断右侧细胞
        if (x < board[0].length -1 && board[y][x +1] > 0){
            survivalNum++;
        }
        // 判断左下角细胞
        if (x > 0 && y < board.length - 1  && board[y + 1][x -1] > 0){
            survivalNum++;
        }
        // 判断下方细胞
        if (y < board.length -1 && board[y + 1][x] > 0) {
            survivalNum++;
        }
        // 判断右下角细胞
        if (x < board[0].length - 1 && y < board.length -1 && board[y + 1][x + 1] > 0) {
            survivalNum++;
        }
         // 最后判断周围存活细胞总数
        if (survivalNum == 3){
            return 1;
        } else if (survivalNum == 2 && present == 1){
            return 1;
        }else {
            return 0;
        }
     }

}
```