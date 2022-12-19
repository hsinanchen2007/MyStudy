class Solution {
 public void gameOfLife(int[][] board) {
        int r = board.length;
        int c = board[0].length;
        for(int i=0;i<board.length;i++) {
        	for(int j=0;j<board[i].length;j++) {
        		a(i,j,board);
        	}
        }
        for(int i=0;i<board.length;i++) {
        	for(int j=0;j<board[i].length;j++) {
        		if(board[i][j]==2) {
        			board[i][j]=0;
        		}
        		if(board[i][j]==-1) {
        			board[i][j]=1;
        		}
        	}
        }
    }

	private void a(int x, int y, int[][] board) {
		// TODO Auto-generated method stub
		 int r = board.length;
	     int c = board[0].length;
	     int sum = 0;
	     for(int i=x-1;i<=x+1;i++) {
	    	 for(int j=y-1;j<=y+1;j++) {
	    		 if(i==x&&j==y) {
	    			 continue;
	    		 }
	    		 if(i>=0&&i<r&&j>=0&&j<c) {
	    			 if(board[i][j]>0) {
	    				 sum++;
	    			 }
	    		 }
	    	 }
	     }
	     if (board[x][y] > 0) {
			if (sum < 2 || sum > 3) {
				board[x][y] = 2;

			}
		}else if(board[x][y]<=0&&sum==3) {
	    	 board[x][y]=-1;
	     }
	}
}