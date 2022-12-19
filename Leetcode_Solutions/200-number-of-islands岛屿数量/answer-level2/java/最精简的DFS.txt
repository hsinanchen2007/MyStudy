### 解题思路
最精简的DFS，gnd
### 代码

```java
class Solution {
   //DFS
	public int numIslands(char[][] grid) {
		if (grid==null||grid.length == 0)return count;
	int m = grid.length;
		int n=grid[0].length;
		for(int i=0;i<m;++i) {
			for(int j=0;j<n;++j) {
				if(grid[i][j]=='1') {
                    ++count;
					donumIslands4(grid,i,j);
				}
			}
		}
		return count;
	}
	int[] dx = { -1, 1, 0, 0 };
	int[] dy = { 0, 0, -1, 1 };
	int count=0;
	private void donumIslands4(char[][] grid, int i, int j) {
		if(i<0||j<0||i>=grid.length||j>=grid[0].length||grid[i][j]!='1')return;
        grid[i][j]='0';
		for(int k=0;k<4;k++) {
			donumIslands4(grid, i+dx[k], j+dy[k]);
		}
	}
}
```