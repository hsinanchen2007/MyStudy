### 解题思路
恨哪！
虽然我的解法没有甜姨的辣么妙，但是我觉得我写得还是挺有逻辑的，但是，居然，超出时间限制！
不管，依然码上！

### 代码

```java
class Solution {
	public int surfaceArea(int[][] grid) {
		// 网格的行、列数
		int row = grid.length;  int col = grid[0].length;
		if (row == 0) return 0;
		int ans = 0;
		// 用于标记格子是事被访问过
		int[][] flag = new int[row][col];
		for (int i=0; i<row; ++i) {
			for (int j=0; j<col; ++j) {
				if (grid[i][j] != 0) flag[i][j] = 1;
			}
		}
		// 没有清空，还有方块没有计算（入队），因为广度优先可能有的不能遍历到
		while (! this.isClean(grid)) {
			Queue<Integer> q_i = new LinkedList<>();
			Queue<Integer> q_j = new LinkedList<>();
			// 找到第一个有方块的位置
			sign:for (int i=0; i<row; ++i) {
				for (int j=0; j<col; ++j) {
					if (grid[i][j]!=0) {
						q_i.offer(i);
						q_j.offer(j);
						ans += this.singleArea(grid[i][j]);
						break sign;
					}
				}
			}
			// 上下左右遍历，四个方向
			int[] map_i = {1,-1,0,0}; int[] map_j = {0,0,1,-1};
			// 队列不为空时，遍历整个图形，广度优先搜索
			while (! q_i.isEmpty()) {
				// 取出横、纵坐标
				int cur_i = q_i.poll(); int cur_j = q_j.poll();
				for (int k=0; k<4; ++k) {
					int new_i = cur_i + map_i[k];
					int new_j = cur_j + map_j[k];
					if (new_i>=0 && new_i<row && new_j>=0 && new_j<col && grid[new_i][new_j]!=0) {
						q_i.offer(new_i); q_j.offer(new_j);
						// 加上这个格子里的方块所增加的表面积
						if (flag[new_i][new_j] == 1) {
							ans += this.singleArea(grid[new_i][new_j]);
							flag[new_i][new_j] = 0;
							
						}
						// 减去这个格子与上一格子重叠的部分
						ans -= 2 * Math.min(grid[cur_i][cur_j], grid[new_i][new_j]);
					}
				}
				// 沉岛法
				grid[cur_i][cur_j] = 0;
			}
		}
		return ans;
	}
	
	private int singleArea(int n) {
		if (n<2) return 6*n;
		return 4*n+2;
	}
	
	private boolean isClean(int[][] grid) {
		int row = grid.length; int col = grid[0].length;
		for (int i=0; i<row; ++i) {
			for (int j=0; j<col; ++j) {
				if (grid[i][j] != 0) return false;
			}
		}
		return true;
	}
}
```