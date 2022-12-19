直接一遍循环即可，每次遇到X就无脑答案加1，然后判断当前位置上边或者左边有没有X，有的话减掉1，没的话不管。
```
class Solution {
    public int countBattleships(char[][] board) {
        int ans=0;
        for(int i=0;i<board.length;i++)
        	for(int j=0;j<board[i].length;j++) {
        		if(board[i][j]=='.')
        			continue;
        		ans++;
        		if(i>0 && board[i-1][j]=='X')
        			ans--;
        		if(j>0 && board[i][j-1]=='X')
        			ans--;
        	}
        return ans;
    }
}
```
