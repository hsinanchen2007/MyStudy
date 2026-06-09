
```
class Solution {
    public int numRookCaptures(char[][] board) {
        int ans = 0;
        int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='R'){
                    for(int k=0;k<4;k++){
                        int x = i+dir[k][0];
                        int y = j+dir[k][1];
                        while(x>0 && x<board.length-1 && y>0 && y<board[0].length-1
                                && board[x][y] == '.'){
                            x = x + dir[k][0];
                            y = y + dir[k][1];
                        }
                        if(board[x][y] == 'p'){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```
