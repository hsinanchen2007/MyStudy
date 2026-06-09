下梯子，从a[0][n]开始，设n为第二重循环的开始，当a[i][n]为负数且n不等于0，加上含此行在内的下面行数（行数-i），当n等于0时，说明从后往前每一列的负数都已加完，此时可令flag=false退出所有循环。当a[i][n]为正数时，直接开始下一行，n为当前j。
```Java
class Solution {
    public int countNegatives(int[][] grid) {
        int sum = 0;
    	int m = grid.length;
    	int n = grid[0].length - 1;
    	for (int i = 0; i < m; ++i) {
    		boolean flag = true;
    		for (int j = n; j >= 0; j--) {
    			if (grid[i][j] < 0 && j != 0) {
    				sum += m - i;
    				continue;
    			}
    			else if(grid[i][j] < 0 && j == 0) {
    				sum += m - i;
    				flag = false;
    				break;
    			}
    			else {
    				n = j;
    				break;
    			}
    		}
    		if (flag == false)
    			break;
    	}
  		return sum;
    }
}
```