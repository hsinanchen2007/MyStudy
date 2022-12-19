```
class Solution {
    public int numRookCaptures(char[][] board) {
        //1、找到白色的车R
        //2、由远及近遍历四个方向
        //3、在四个方向上找第一个不为.的点
        //4、如果为p则加1并停止
        int ans = 0;
        for(int r = 0;r < 8;r++){
            for(int c = 0;c < 8;c++){
                if(board[r][c] == 'R'){
                    int i = r, j = c;
                    while(i >= 1 && board[--i][j] == '.');
                    if(i >= 0 && board[i][j] == 'p') ans++;
                    i = r;
                    j = c;
                    while(i < 7 && board[++i][j] == '.');
                    if(i < 8 && board[i][j] == 'p') ans++;
                    i = r;
                    j = c;
                    while(j >= 1 && board[i][--j] == '.');
                    if(j >= 0 && board[i][j] == 'p') ans++;
                    i = r;
                    j = c;
                    while(j < 7 && board[i][++j] == '.');
                    if(j < 8 && board[i][j] == 'p') ans++;
                    break;
                }
            }
        }
        return ans;
    }
}
```
