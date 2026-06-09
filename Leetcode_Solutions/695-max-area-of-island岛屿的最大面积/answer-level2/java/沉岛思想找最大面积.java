### 解题思路
此处撰写解题思路
1. 先定义dfs函数（深度优先搜索，递归思想）。当找到0时，返回0；若找到的是1，则搜索其上下左右是否为1，返回值为num + 上下左右的dfs值。此时最重要的一步：沉岛，即将当前值置为0，防止再找一遍
2. 主函数，遍历，对每一个数进行深度优先搜索，而且同一个岛不会搜索两遍，因为在第一遍时已经被沉没了！
3. 非常巧妙的方法
4. 时间复杂度为O(n2)
### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
		int row = grid.length;
		int col = grid[0].length;
		int max = 0;
		for (int i=0; i<row; i++) {
			for (int j=0; j<col; j++) {
				max = Math.max(max, dfs(grid, i, j));
			}
		}
		return max;
	}
	
	private int dfs(int[][] grid, int i, int j) {
		int row = grid.length;
		int col = grid[0].length;
		if (i<0 || j<0 || i>=row || j>=col || grid[i][j]==0) return 0;
		int num = 1;
		// 沉岛
		grid[i][j] = 0;
		num += dfs(grid, i+1, j);
		num += dfs(grid, i-1, j);
		num += dfs(grid, i, j+1);
		num += dfs(grid, i, j-1);		
		return num;
	}
}
```