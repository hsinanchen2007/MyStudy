### 代码

#### DFS

```cpp
class Solution {
public:
	void dfs(vector<vector<char>>& grid, int x, int y)
	{
		//边界条件，x，y在范围内或者该点不为陆地
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0') return;
		grid[x][y] = '0';//访问过的点设置为0
		array<int, 4> dx = { 0,0,-1,1 };
		array<int, 4> dy = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + x;
			int nextY = dy[i] + y;
			dfs(grid, nextX, nextY);
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					ans++;
					dfs(grid, i, j);
				}
			}
		}
		return ans;
	}
};
```

#### BFS
```cpp
class Solution {
public:
	void bfs(vector<vector<char>>& grid, int x, int y)
	{
		//增量数组
		array<int, 4> dx = { 0,0,-1,1 };
		array<int, 4> dy = { 1,-1,0,0 };
		queue<pair<int, int>> q;
		q.push({ x,y });
		while (!q.empty())
		{
			pair<int, int> top = q.front();
			grid[top.first][top.second] = '0';
			q.pop();//出队
			for (int i = 0; i < 4; i++)
			{
				int nextX = top.first + dx[i];
				int nextY = top.second + dy[i];
				if (nextX >= 0 && nextX < grid.size() && nextY >= 0 && nextY < grid[0].size() && grid[nextX][nextY] == '1')
				{
					//压入未被访问的陆地地址
					//将该块网格标记为'0'
					q.push({ nextX,nextY });
					grid[nextX][nextY] = '0';
				}
			}
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					ans++;
					grid[i][j] = '0';
					bfs(grid, i, j);
				}
			}
		}
		return ans;
	}
};
```