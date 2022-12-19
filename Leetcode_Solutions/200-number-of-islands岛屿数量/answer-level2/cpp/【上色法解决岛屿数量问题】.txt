### 解题思路
使用深度优先搜素，只要相邻就上色，最后判断未上色的数量

### 代码

```cpp
class Solution {
public:
    int n, m;
    void Islands_DFS(vector<vector<char>>& grid, int x, int y) {
	if (x < 0 || y<0 || x>n - 1 || y>m - 1 || grid[x][y] != '1') return;
	grid[x][y] = '0';
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };//---四连通
	for (int i = 0; i < 4; i++)
		Islands_DFS(grid, x + dx[i], y + dy[i]);
}
    int numIslands(vector<vector<char>>& grid) {
	int count = 0;
	n = grid.size();
	if (n < 1) return 0;
	m = grid[0].size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '1') {
				Islands_DFS(grid, i, j);
				count++;
			}
	return count;
}
};
```