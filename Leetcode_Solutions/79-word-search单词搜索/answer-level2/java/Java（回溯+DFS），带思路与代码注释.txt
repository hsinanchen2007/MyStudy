思路：
1.先找到起点；
2.对当前坐标进行判断，如与字符串相应位置的字符相符，进行下一步；
3.深度优先遍历，判断当前点的上下左右坐标是否在范围内；
4.对符合条件的坐标进行回溯，即回到第2步；
5.回溯终止的条件是字符串遍历结束。
```
class Solution {
    //标志位，如果已经=true，不用进行后面的遍历搜索
    boolean flag = false;

    public boolean exist(char[][] board, String word) {
        //找到起始位置
        for(int i=0; i<board.length; i++) {
            for(int j=0; j<board[0].length; j++) {
                if(!flag&&board[i][j]==word.charAt(0))
                    backtrack(0, word.toCharArray(), i, j, board);
            }
        }
        return flag;
    }

    //i：当前判断的字符位置，x,y：board中的坐标
    private void backtrack(int i, char[] word, int x, int y, char[][] board) {
        if(!flag&&i==word.length-1&&word[i]==board[x][y]) {
            flag=true;
        }
        if(!flag&&i<word.length-1&&word[i]==board[x][y]) {
            //坐标位移，分别对应上下左右
            int[] p1 = {-1, 1, 0, 0}, p2 = {0, 0, -1, 1};
            //深度优先遍历
            for(int j=0; j<4; j++) {
                int next_x = x + p1[j];
                int next_y = y + p2[j];
                if(next_x>=0&&next_x<board.length&&next_y>=0&&next_y<board[0].length) {
                    //对当前坐标做标记，防止重复使用
                    board[x][y] = '1';
                    backtrack(i+1, word, next_x, next_y, board);
                    //恢复当前坐标
                    board[x][y] = word[i];
                }
            }
        }
    }
}
```
