### 解题思路

/*
    1.对于本身就是活细胞来说
        // 1.周围活细胞数为0,1 则死亡
        // 2.周围活细胞数为2,3 则存活
        // 3.周围活细胞数为4,5,6,7,8 则死亡
        周围活细胞数为2,3 则存活
    2.对于本身就是死细胞来说
        周围活细胞数为3 则存活
*/

/*		(row,col)
     * 		(-1,-1)(-1,0)(-1,1)
     * 		(0,-1)(0,0)(0,1)
     * 		(1,-1)(1,0)(1,1)
     * 
     * 
     */

### 代码

```java
class Solution {
       public void gameOfLife(int[][] board) {
    	
    	int[][] book=new int[board.length][board[0].length];
    	
    	for(int i=0;i<board.length;i++) {
    		for(int j=0;j<board[0].length;j++) {
    			int count=0;
    			
    			//先统计每个坐标处周围存活的细胞个数,如果坐标是活细胞则多算一个
    			for(int k_row=-1;k_row<=1;k_row++) {
    				for(int k_col=-1;k_col<=1;k_col++) {
    					if(isLife(board,i+k_row,j+k_col)) count++;
    				}
    			}
    			
    			//如果i，j处是活细胞，刚多算一个
    			if(board[i][j]==1) {
    				if(count==3||count==4) book[i][j]=1;
    				else book[i][j]=0;
    			}	
    			//如果i，j处是死细胞
    			else {
    				if(count==3) book[i][j]=1;
    				else book[i][j]=0;
    			}	
    		}
    	}	
    	
    	for(int i=0;i<board.length;i++) {
    		for(int j=0;j<board[0].length;j++) {
    			board[i][j]=book[i][j];
    		}
    	}
    	
    }
	
    
    public  boolean isLife(int[][] board,int row,int col) {
    	
    	if(row<0||col<0||col>=board[0].length||row>=board.length) return false;
    	
    	return board[row][col]==1;
    }
}

```