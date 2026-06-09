### 解题思路
dfs步骤：
1.对于board[i][j],我们需要搜索它的八个方向有多少雷,若有M或X,则计数加一
2.若数量为0，直接将E改为B,否则改为对应的数字
3.若为0，代表四周没有雷，继续dfs递归
4.若有雷，结束搜索
5.注意边界条件


### 代码

```java
class Solution {
    private char[][] board;
    private boolean[][] isUpdated;
    private int height,width;
    private int[][] directions=new int[][]{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    public char[][] updateBoard(char[][] board, int[] click) {
        this.board=board;
        if (board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
        }else {
            height=board.length;
            width=board[0].length;
            isUpdated=new boolean[height][width];
            dfs(click[0],click[1]);
        }
        return board;
    }

    private void dfs(int i,int j){
        if (i<0||j<0||i>=height||j>=width||isUpdated[i][j]||board[i][j] =='X'){
            return;
        }else {
            if (board[i][j] =='E') {
                int result=0;
                for (int[] direction : directions) {
                    int currI=i+direction[0];
                    int currJ=j+direction[1];
                    if (!(currI<0||currJ<0||currI>=height||currJ>=width)){
                        result = board[currI][currJ]=='X'||board[currI][currJ] =='M'?result+1:result;
                    }
                }
                if (result == 0) {
                    board[i][j]='B';
                    isUpdated[i][j]=true;
                    for (int[] direction : directions) {
                        int currI=i+direction[0];
                        int currJ=j+direction[1];
                        if (!(currI<0||currJ<0||currI>=height||currJ>=width)){
                            dfs(currI,currJ);
                        }
                    }
                }else {
                    board[i][j]=(char)(result+'0');
                }
            }
        }
    }
}
```