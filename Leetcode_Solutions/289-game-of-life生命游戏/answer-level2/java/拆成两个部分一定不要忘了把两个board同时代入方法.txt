
一定要把两个board同时代入方法，用原board做判断，在新board上修改！
一定要把两个board同时代入方法，用原board做判断，在新board上修改！
一定要把两个board同时代入方法，用原board做判断，在新board上修改！

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
    	int[][]previous=new int[board.length][board[0].length];
    	for (int i = 0; i < previous.length; i++) {
			for (int j = 0; j < previous[0].length; j++) {
				previous[i][j]=board[i][j];
			}
		}
    	//复制一遍原grid用于变动，但是要new一个，不然改动还是指向之前那个
    	for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				board[i][j]=search(i,j,previous,board);
				
				
			}
		} 	
    }
    public static int search(int x,int y,int[][]previous,int[][]board) {   
		int[]neighbors= {0,1,-1};  //建立数组用于表示方向
		int sum=0; //存放活细胞的个数
		for (int i = 0; i < 3; i++) {        
			for (int j = 0; j < 3; j++) {
				if (!(neighbors[i]==0&&neighbors[j]==0)) {         //遍历8个方向
					int c= (x+neighbors[i]);
					int r= (y+neighbors[j]);
					if ((c>=0&&c<previous.length)&&(r>=0&&r<previous[0].length)&&(previous[c][r]==1)) {   //找活细胞
						sum+=1;
					}
				}
			}
		}
		//只传入一个grid,又改变了原grid的状态，应该传入两个grid，在新board上直接修改
		if (previous[x][y]==1&&(sum<2||sum>3)) {
			board[x][y]=0;     
		}
		if (previous[x][y]==0&&sum==3) {
			board[x][y]=1;
		}
		
		return board[x][y];
    }
}
```