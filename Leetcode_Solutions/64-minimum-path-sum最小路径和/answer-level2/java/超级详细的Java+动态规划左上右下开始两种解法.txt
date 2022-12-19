
	 * 自顶向下计算方法：每次只能向右或者向下走，分析其中一个点，
	 * 在经过第一列的每个点D(i,0)时：必然经过点D(i-1,0),那么第一列的状态转移方程为：f(i,0)=f(i-1,0)+D(i,0)
	 * 在经过第一行的每个点D(0,j)时：必然经过点D(0,j-1),那么第一行的状态转移方程为：f(0,j)=f(0,j-1)+D(0,j)
	 * 在经过非边界点D(i,j)时，必然经过具有min(f(i,j-1),f(i-1,j))的点，那么非边界点的状态转移方程为：
	 * f(i,j)=min(f(i,j-1),f(i-1,j))+D(i,j);
	 * */
	public static int minPathSum(int[][] grid) {
		int row=grid.length;
		int col=grid[row-1].length;
		int[][] res=new int[row][col];
		res[0][0]=grid[0][0];
		for(int i=1;i<row;i++){
			res[i][0]=res[i-1][0]+grid[i][0];
			
		}
		for(int j=1;j<col;j++){
			res[0][j]=res[0][j-1]+grid[0][j];
		}
		for(int i=1;i<row;i++)
			for(int j=1;j<col;j++)
			{
				res[i][j]=Math.min(res[i][j-1], res[i-1][j])+grid[i][j];
				
				
			}
		return res[row-1][col-1];
        
    }

	 * 自底向上计算方法：分析其中一个点：
	 * 经过最下面一行每个点D(row-1,j)时，必然经过点D(row-1,j+1),所以最后一行的状态转移方程为：f(row-1,j)=f(row-1,j+1)+D(row-1,j);
	 * 经过最右边的列中每个点D(i,col-1)时，必然经过D(i+1,col-1)，所以最后一列的状态转移方程为：f(i,col-1)=f(i+1,col-1)+D(i,col-1);
	 * 经过非边界点D(i,j)时，必然经过具有min(f(i+1,j),f(i,j+1))的点，所以非边界点的状态转移方程为
	 * f(i,j)=min(f(i+1,j),f(i,j+1))+D(i,j);
	 * 
	 * */
	public static int minPathSum2(int[][] grid){
		int row=grid.length;
		int col=grid[row-1].length;
		int[][] res=new int[row][col];
		res[row-1][col-1]=grid[row-1][col-1];
		for(int i=row-2;i>=0;i--){
			res[i][col-1]=res[i+1][col-1]+grid[i][col-1];
		}
		for(int j=col-2;j>=0;j--){
			res[row-1][j]=res[row-1][j+1]+grid[row-1][j];
		}
		for(int i=row-2;i>=0;i--)
			for(int j=col-2;j>=0;j--){
				res[i][j]=Math.min(res[i+1][j], res[i][j+1])+grid[i][j];
			}
		return res[0][0];
		
		
	}
```





