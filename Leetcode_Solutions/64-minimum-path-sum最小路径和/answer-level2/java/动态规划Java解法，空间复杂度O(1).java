空间复杂度O(1)，时间复杂度O(m*n)
和官方题解思路相似，不过官方题解是从右下开始推的，我这个起点在左上
```
	public int minPathSum(int[][] grid) {
		int m = grid.length;//列
		int n = grid[0].length;//行
		for(int i=1;i<m;i++){
			grid[i][0] = grid[i-1][0]+grid[i][0];
		}
		for(int i=1;i<n;i++){
			grid[0][i] = grid[0][i-1]+grid[0][i];
		}
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				grid[i][j] = Math.min(grid[i-1][j], grid[i][j-1])+grid[i][j];
			}
		}
        return grid[m-1][n-1];
    }
```
