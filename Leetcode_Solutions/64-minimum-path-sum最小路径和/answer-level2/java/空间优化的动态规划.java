class Solution {
	    public int minPathSum(int[][] grid) {
	        int row = grid.length;
	        int column = grid[0].length;
	        
	        int[] cur =new int[column];
	        int[] pre = new int[column];
	        if(row==0||column==0)return 0;
	        for(int i=0;i<column;i++){
	            int sum=0;
	            for(int j=0;j<=i;j++){
	                sum=sum+grid[0][j];
	            }
	            cur[i]=sum;
	        }

	        

	        for(int i=1;i<row;i++){
	        	pre=cur;
	            for(int j=0;j<column;j++){
	                if(j==0)
	                  cur[j]=pre[j]+grid[i][j];
	                else
	                  cur[j] = Math.min(pre[j],cur[j-1])+grid[i][j];
	            }
	            
	           
	        }
	        return cur[column-1];
	    }
	
}

          
        