代码写得有点点长 ..毕竟比赛嘛
但是可以理解思路重新写一下。

一开始容易想成是dp，但是仔细一想！ 发现bfs就能解决。
流程如下
首先先找到cost为0时 能够遍历到的点，并将他们储存起来。
然后将这些点设置成可以修改方向的点(即向四个方向扩展)，这样cost就+1了，重新观察这些点能够去的最大的地方。
同样，只要是没找到最终的目标，一直按照这个思路寻找下去。
最终找到目标以后，返回这个cost就是最终解了

```
class Solution {
	bool vis[105][105];
	int dx[5] = { 0,0,0,1,-1 };
	int dy[5] = { 0,1,-1,0,0 };
public:
	int minCost(vector<vector<int>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		if (row == 1 && col == 1) return 0;
		memset(vis, false, sizeof(vis));
		queue<vector<int>> q;
		q.push({ 0,0 });
		vis[0][0] = true;
		int cost = 0;
		vector<vector<int>> level;
		level.push_back({ 0,0 });
		while (!q.empty()) {
			auto temp = q.front(); q.pop();
			int x = temp[0], y = temp[1];

			int di = grid[x][y]; //表示方向
			//如果di为-1，表示可以去任何的方向
			if (di == -1) {
				for (int k = 1; k <= 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					while (nx >= 0 && nx < row && ny >= 0 && ny < col && !vis[nx][ny]) {
						vis[nx][ny] = true;
						level.push_back({ nx,ny });
						int dir = grid[nx][ny];
						nx += dx[dir];
						ny += dy[dir];
					}
				}
			}
			else {
				//只能去一个方向
				int nx = x + dx[di], ny = y + dy[di];
				while (nx >= 0 && nx < row && ny >= 0 && ny < col && !vis[nx][ny]) {
					vis[nx][ny] = true;
					level.push_back({ nx,ny });
					int dir = grid[nx][ny];
					nx += dx[dir];
					ny += dy[dir];
				}
			}

			if (q.empty() && !level.empty()) {
				
				for (auto p : level) {
					if (p[0] == row - 1 && p[1] == col - 1) return cost;
					q.push(p);
					grid[p[0]][p[1]] = -1; //表示这些点可以去任何的方向
				}
				cost++;
				level.clear();
			}
		}
		return cost;
	}
};
```
