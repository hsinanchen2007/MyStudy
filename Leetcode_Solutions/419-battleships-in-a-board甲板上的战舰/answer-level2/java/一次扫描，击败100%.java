```
class Solution {
    //一次扫描获得结果
    //从上到下，从左到右扫描
    //若当前节点正上方/左方节点为X，跳过此节点
    public int countBattleships(char[][] board) {
        int res = 0;
        for (int i=0;i<board.length;i++)
            for (int j=0;j<board[0].length;j++)
                if (board[i][j]=='X')
                    if (i==0 && j==0)
                        res += 1;
                    else if (i>0 && j>0)
                        res += (board[i-1][j] == '.' && board[i][j-1] == '.')?1:0;
                    else if (i>0)
                        res += board[i-1][j] == '.'?1:0;
                    else 
                        res += board[i][j-1] == '.'?1:0;
        return res;            
    }
}
```
