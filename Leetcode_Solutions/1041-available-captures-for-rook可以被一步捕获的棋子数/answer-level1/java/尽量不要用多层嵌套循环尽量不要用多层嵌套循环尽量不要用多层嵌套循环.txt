### 解题思路
沙雕题目，本来把车的位置给出来就很清楚的，非要绕着。
尼玛废了劳资整整一天才绕清楚。
长个记性，尽量不要用多层嵌套循环尽量不要用多层嵌套循环尽量不要用多层嵌套循环。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
    	int sum=0;						//这个方法的功能就只有找到车的坐标和返回sum值
    	for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {   
				if (board[i][j]=='R') {
					sum=search(board,i,j);
				}
			}
    	}
		return sum;		
    }
    public static int search(char[][]board,int i,int j) { //新建一个方法专门用于查找
    	int sum=0;	
    	for (int x = j;  x< board[0].length; x++) {      //四个方向分别找
			if (board[i][x]=='p') {
				sum++;
				break;
			}
			if (board[i][x]=='B') {
				break;
			}
		}
    	for (int x = j;  x>=0; x--) {
			if (board[i][x]=='p') {
				sum++;
				break;
			}
			if (board[i][x]=='B') {
				break;
			}
		}
    	for (int y = i;  y< board.length; y++) {
			if (board[y][j]=='p') {
				sum++;
				break;
			}
			if (board[y][j]=='B') {
				break;
			}
		}
    	for (int y = i;  y>=0; y--) {
			if (board[y][j]=='p') {
				sum++;
				break;
			}
			if (board[y][j]=='B') {
				break;
			}
		}
		return sum;
    }
}
```