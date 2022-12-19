### 解题思路
用穷举法来考虑每一个细胞与周围细胞情况。可能这是最简单的思路了，其他的实在没有想出来。

### 代码

```java
class Solution {
  static int board1[][];
  public static void gameOfLife(int[][] board) {
			 board1=board;
			 boolean falg=true;
			 int r=board.length;
			 int c=board[0].length;
			 int a[][]=new int[r][c];
			 for(int i=0;i<r;i++) {
				 for(int z=0;z<c;z++) {
					 if(r==1||c==1) {
						 board[i][z]=0;
						 falg=false;
						 continue;
					 }
					a[i][z]=board[i][z];
				 }
			 }
			 if(!falg) {
				 return;
			 }
		
			 for(int i=0;i<r;i++) {
				 for(int j=0;j<c;j++) {
					 if(i==0&&j==0) {
						 int s=a[i][j+1]+a[i+1][j]+a[i+1][j+1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(i==0&&j<c-1) {
						 int s=a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(i==0&&j==c-1) {
						 int s=a[i][j-1]+a[i+1][j]+a[i+1][j-1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(j==0&&i<r-1) {
						 int s=a[i-1][j]+a[i-1][j+1]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(j==c-1&&i<r-1) {
						 int s=a[i-1][j-1]+a[i-1][j]+a[i][j-1]+a[i+1][j-1]+a[i+1][j];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(j==0&&i==r-1) {
						 int s=a[i-1][j]+a[i-1][j+1]+a[i][j+1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(j<c-1&&i==r-1) {
						 int s=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 if(j==c-1&&i==r-1) {
						 int s=a[i-1][j-1]+a[i-1][j]+a[i][j-1];
						 board[i][j]=juged(s,i,j);
						 continue;
					 }
					 else {
					 int s=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
					 board[i][j]=juged(s,i,j);
					 continue;}
				 }
			 }
			
		    }
		public static int juged(int s,int i,int j) {
			if(s<2) {
				return 0;
			}
			if(s==2) {
				if(board1[i][j]==0) {
					return 0;
				}
				return 1;
			}
			if(s==3) {
				return 1;
			}
			return 0;
		}
}
```