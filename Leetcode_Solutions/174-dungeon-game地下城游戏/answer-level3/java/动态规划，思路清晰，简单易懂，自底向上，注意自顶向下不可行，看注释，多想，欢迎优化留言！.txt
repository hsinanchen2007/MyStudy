```
 public int calculateMinimumHP(int[][] dungeon) {
    //地下城游戏解法
	//dp动规,dp[i][j]表示骑士从索引坐标（i,j）到地下城右下角的索引坐标所需要的最小初始能量
	//对此二维矩阵，自上而下的动规是不行的，因为如果进行自上而下的动规，就会牵涉到当前最优解与当前拥有利益值，无法动规下去
	//联想到记忆化回朔解法，从而想到对于二维矩阵，记忆化回朔可以改写成自下而上的动态规划
	int row=dungeon.length,col=dungeon[0].length;
	int[][] dp=new int[row][col];
	for(int r=row-1;r>-1;r--)
		for(int c=col-1;c>-1;c--) {
	       if(r==row-1&&c==col-1) {
	    	   dp[row-1][col-1]=dungeon[row-1][col-1]<0?1-dungeon[row-1][col-1]:1; continue;
	       }
	       if(r+1<row) {
	    	   if(dungeon[r][c]>=0) {
	    		   if(1+dungeon[r][c]>=dp[r+1][c]) dp[r][c]=1;
	    		   else dp[r][c]=dp[r+1][c]-dungeon[r][c];
	    	   }
	    	   else dp[r][c]=dp[r+1][c]-dungeon[r][c];
	       }
	       if(c+1<col) {
	    	   int value;
	    	   if(dungeon[r][c]>=0) {
	    		   if(1+dungeon[r][c]>=dp[r][c+1]) value=1;
	    		   else value=dp[r][c+1]-dungeon[r][c];
	    	   }
	    	   else value=dp[r][c+1]-dungeon[r][c]; 
	    	   if(r+1<row&&value>dp[r][c]) ;
	    	   else dp[r][c]=value;
	       }
		}
	return dp[0][0];
    }
```
