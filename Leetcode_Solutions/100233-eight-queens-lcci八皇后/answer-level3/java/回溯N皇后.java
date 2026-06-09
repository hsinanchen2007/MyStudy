### 解题思路
回溯算法的典型题
对于每一行来说，有N个位置可供选择，选择一个有效的位置，然后进行下一行的选择，
当到达最后一行时，加入结果，回溯，一直回溯到第一行，然后选择下一个有效的位置，然后进行下一行的选择。。。。

### 代码

```java
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<List<String>>();
        char[][] grid = new char[n][n];
        for(char[] r : grid) {
        	Arrays.fill(r, '.');
        }
        backtrack(0, n, grid, ans);
		return ans;
    }
    private void backtrack(int row, int n,char[][] grid,List<List<String>> ans){
    	if(row == n) {
    		List<String> list = new ArrayList<String>();
    		for(char[] r : grid) {
    			list.add(new String(r));
    		}
    		ans.add(list);
    		return;
    	}
    	for(int i = 0 ; i < n; i++) {
    		if(valid(grid, n, row, i)) {
    			grid[row][i] = 'Q';
    			backtrack(row + 1, n, grid, ans);
    			grid[row][i] = '.';
    		}
    	}
    }
    
    private boolean valid(char[][] grid, int n,int x, int y) {
    	for(int c = 0; c < n; c++) {
    		if(grid[x][c] == 'Q') {
    			return false;
    		}
    	}
    	for(int r = 0; r < x; r++) {
    		if(grid[r][y] == 'Q') {
    			return false;
    		}
    	}
    	int tx = x-1;
    	int ty = y-1;
    	while(tx >= 0 && ty >= 0) {
    		if(grid[tx--][ty--] == 'Q') {
    			return false;
    		}
    	}
    	tx = x - 1;
    	ty = y + 1;
    	while(tx >= 0 && ty < n) {
    		if(grid[tx--][ty++] == 'Q') {
    			return false;
    		}
    	}
		return true;
    	
    }
}
```