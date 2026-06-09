为满足题目要求，不修改board，只使用O(1)空间并且只遍历一次，那么我们可以每次遍历到'X'时判断一下当前的X是不是和之前遍历的X统计的是同一艘战舰，判断方法，如果左边没有越界，那么左边是'.'才不会重复统计，同理上面也一样。

```
class Solution {
    public int countBattleships(char[][] board) {
        int res=0;
        for(int i=0;i<board.length;i++)
            for(int j=0;j<board[0].length;j++)
                if(board[i][j]=='X')
                    if((i-1<0||i-1>=0&&board[i-1][j]=='.')&&(j-1<0||j-1>=0&&board[i][j-1]=='.'))
                        res++;
        return res;
    }
}
```
