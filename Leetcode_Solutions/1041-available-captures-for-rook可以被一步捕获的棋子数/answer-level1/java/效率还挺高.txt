


代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int cnt = 0;
		if(board==null || board.length==0) {
			return cnt;
		}		
		// 四个方向
		int[][] directions = {
				{-1,0},
				{0,1},
				{1,0},
				{0,-1},
		};
		
		// 找到车的位置 
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if(board[i][j]=='R') {
					int x = i, y = j, tx = x, ty = y;
					for (int k = 0; k < directions.length; k++) {
						x += directions[k][0];
						y += directions[k][1];
						// 判断当前位置是否正确
						if(check(board,x,y)) {
							// 是象跳出本次循环 回溯车的位置
							if(board[x][y]=='B') {
                                x = tx;
								y = ty;
								continue;
							}
							// 是小兵 +1 跳出本次循环 回溯车的位置
							if(board[x][y]=='p') {
								cnt++;
                                x = tx;
								y = ty;
								continue;
							}
							// 是空格继续当前方向搜索
							if(board[x][y]=='.') {
								k -= 1;
							}
						}else {
							// 回溯车的位置
							x = tx;
							y = ty;
							continue;
						}
					}					
					break;				
				}
			}
		}
		return cnt;		
    }
    private static boolean check(char[][] board, int x, int y) { 
		if(x<0 || x>=board.length || y<0 || y>=board[0].length) { 
			return false;
			} 
		return true; 
	 }

}
```