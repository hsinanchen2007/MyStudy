### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    // rows数组用来记录每一行有哪些数字已经用过了(cols同理)
    private boolean[][] rows = new boolean[9][10];
    private boolean[][] cols = new boolean[9][10];
    // cubes用来记录每一个大方块里面已经用了哪些数字
    private boolean[][][] cubes = new boolean[3][3][10];
    private char[][] board;
    public void solveSudoku(char[][] board) {
        this.board = board;
        // 遍历数组来填充rows, cols和cube这三个数组
        for(int x = 0; x < 9; x++){
            for(int y = 0; y < 9; y++){
                if(board[x][y] == '.'){
                    continue;
                }
                int element = board[x][y] - '0';
                rows[x][element] = true;
                cols[y][element] = true;
                cubes[x/3][y/3][element] = true;
            }
        }
        backtracking(0, 0);
        return;
    }
    // 回溯过程
    private boolean backtracking(int x, int y){
        // x超过了界限, 说明每个点都遍历过了
        if(x == 9){
            return true;
        }
        // 走到了每一行的终点
        if(y == 9){
            // 从下一行开始,还要判断是否board已经到过头了, 如果到过了返回true，反之返回false
            boolean toEnd = backtracking(x+1, 0);
            return toEnd;
        }
        if(board[x][y] == '.'){
            boolean life = false;
            for(int i = 1; i <= 9; i++){
                if(!rows[x][i] && !cols[y][i] && !cubes[x/3][y/3][i]){
                    life = true;
                    board[x][y] = (char)(i + '0');
                    rows[x][i] = true;
                    cols[y][i] = true;
                    cubes[x/3][y/3][i] = true;
                    boolean toEnd = backtracking(x, y+1);
                    // 如果board到过头了，则直接返回
                    if(toEnd){
                        return true;
                    }
                    // 回溯法要还原现场
                    board[x][y] = '.';
                    rows[x][i] = false;
                    cols[y][i] = false;
                    cubes[x/3][y/3][i] = false;
                }
            }
            // life还是false，说明九个数字一个都填不进去，直接返回false；
            if(!life){
                return false;
            }
        }
        else{
            boolean toEnd = backtracking(x, y+1);
            if(toEnd){
                return true;
            } 
        }
        return false;
    }
}
```