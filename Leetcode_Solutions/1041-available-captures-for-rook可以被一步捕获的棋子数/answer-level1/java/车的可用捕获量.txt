### 解题思路
1.获取R字符的位置存x,y坐标
2.分别判断四个方向是否有p有则cnt++,中间遇到B和边界返回
3.返回cnt

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
int x = 0;
		int y = 0;
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if(board[i][j]=='R'){
					x = i;
					y = j;
					break;
				}
			}
		}
		char c;
		int cnt = 0;
		for (int i = x-1; i >= 0 ; i--) {
			c = board[i][y];
			if(c == '.') continue;
            if(c == 'B') break;
            if(c == 'p') {
            	cnt += 1;
                break;
            }
		}
		for (int i = x+1; i < board.length; i++) {
			c = board[i][y];
			if(c == '.') continue;
            if(c == 'B') break;
            if(c == 'p') {
            	cnt += 1;
                break;
            }
		}
		for (int i = y-1; i >= 0 ; i--) {
			c = board[x][i];
			if(c == '.') continue;
            if(c == 'B') break;
            if(c == 'p') {
            	cnt += 1;
                break;
            }
		}
		for (int i = y+1; i < board.length; i++) {
			c = board[x][i];
			if(c == '.') continue;
            if(c == 'B') break;
            if(c == 'p') {
            	cnt += 1;
                break;
            }
		}
			
		return cnt;
    }
}
```