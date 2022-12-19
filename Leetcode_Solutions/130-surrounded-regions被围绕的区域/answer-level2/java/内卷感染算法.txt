### 解题思路
请参考注释和代码，写的已经非常详细了

### 代码

```java
class Solution {
    // 辅助类，主要是往stack中放的时候要记住位置
    class XONode {
        int row;
        int col;
        XONode(int r, int c){
            row = r;
            col = c;
        }
    }

    /**
     * 解题思路 - 感染算法
     * 反向思考，如果一个O不是被围死的那么它必然有办法通过各种路径找到靠边的O
     * 那么就是说，以靠边的O作为起点，向内不断遍历（自走），只要将所有的联通的O标记为"活"
     * 那么剩下的O必然就是死的
     * 在这个过程中，被标记过的"O"不需要再次被标记
     * 当一个标记的过程，其上下左右要么是X要么是被标记过的O的时候，就结束了
     * 途中任何遇到的新O都会被加入到栈中，进行下一次标记
     *
     * @param board
     */
    public void solve(char[][] board) {
        int rows = board.length;
        if(rows<=2){
            return;
        }
        int cols = board[0].length;

        // 2X2矩阵根本封不住
        // 且任何行或者列为3以下的都不可能封得住
        if(cols <= 2){
            return;
        }

        // 围着边缘绕一圈
        // 只有边上的'O'可达的其他'O'都是活的
        // 绕圈的时候要记住自走的方向
        int i=0,j=0;
        String direct = "east";
        do {
            // 处理逻辑
            // System.out.println("board["+i+"]["+j+"]");
            if(board[i][j] == 'O'){
                // 以此为根root进行爬虫
                XONode node = new XONode(i, j);
                nodeWalking(node,board);
            }

            // 判断方向
            if("east".equals(direct)){
                if(i == 0 && j==cols-1){
                    // 方向变为向下
                    direct = "south";
                    i++;
                    continue;
                }
                // 继续向右走一格
                j++;
                continue;
            }
            if("south".equals(direct)){
                if(i == rows-1 && j==cols-1){
                    // 方向变为向左
                    direct = "west";
                    j--;
                    continue;
                }
                i++;
            }
            if("west".equals(direct)){
                if(i == rows-1 && j==0){
                    // 方向变为向左
                    direct = "north";
                    i--;
                    continue;
                }
                j--;
            }
            if("north".equals(direct)){
                // 方向变为向北
                i--;
            }
        // 没有回到起点就一直爬    
        }while( !(i==0 && j==0));

        // 将爬虫标记完的# 转换成O
        // 将剩余的O变为X
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c] == '#'){
                    board[r][c] = 'O';
                }else if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
            }
        }

    }

    private void nodeWalking(XONode node, char[][] board) {
        Stack<XONode> stack = new Stack<>();
        stack.push(node);
        int rows = board.length;
        int cols = board[0].length;
        while(stack.size()>0){
            XONode me = stack.pop();
            // 如果我本身已经靠墙了
            // 那么我所有精力过的O节点都是活的
            // 活节点必须标记成"#"，这代表我是O，但我永久不可能被封闭
            board[me.row][me.col] = '#';

            // 向上看看
            if(me.row-1 >= 0 && board[me.row-1][me.col] == 'O'){
                XONode up = new XONode(me.row-1,me.col);
                stack.push(up);
            }

            // 向左看看
            if(me.col-1 >= 0 && board[me.row][me.col-1] == 'O'){
                XONode left = new XONode(me.row,me.col-1);
                stack.push(left);
            }

            // 向右看看
            if(me.col+1 <= cols-1 && board[me.row][me.col+1] == 'O'){
                XONode right = new XONode(me.row,me.col+1);
                stack.push(right);
            }

            // 向下看看
            if(me.row+1 <= rows-1 && board[me.row+1][me.col] == 'O'){
                XONode down = new XONode(me.row+1,me.col);
                stack.push(down);
            }
        }
    }
}
```