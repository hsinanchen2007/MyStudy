```
class Solution {
public:
	int m, n;
	int dfs(vector<vector<int>>& grid, int i, int j)
	{
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
			return 0;
		grid[i][j] = 2;
		return dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + 1;
	}
	vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
		m = grid.size();
		n = grid[0].size();
		vector<int>res(hits.size());
		for (int i = 0; i < hits.size(); i++)
			grid[hits[i][0]][hits[i][1]]--;
		for (int i = 0; i < n; i++)
		{
			if (grid[0][i] == 1)
				dfs(grid, 0, i);
		}
		for (int i = hits.size() - 1; i >= 0; i--)
		{
			int x = hits[i][0];
			int y = hits[i][1];
			grid[x][y]++;
			if (grid[x][y] == 1)
			{
				if ((x - 1 >= 0 && grid[x - 1][y] == 2) ||
					(x + 1 < m && grid[x + 1][y] == 2) ||
					(y - 1 >= 0 && grid[x][y - 1] == 2) ||
					(y + 1 < n && grid[x][y + 1] == 2) ||
					(x == 0))
					res[i] = dfs(grid, x, y)-1;
			}
		}
		return res;
	}
};
```
