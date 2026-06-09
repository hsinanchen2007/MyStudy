```c++
 int orangesRotting(vector<vector<int>>& grid) {
	vector<vector<int>> isvisited(grid.size(), vector<int>(grid[0].size(), 0));
	int cnt = 0;
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	queue<pair<int, int>> q;
	for (int i = 0; i<grid.size(); ++i){
		for (int j = 0; j<grid[0].size(); ++j){
			if (grid[i][j] == 2){
				q.push(make_pair(i, j));//烂橘子入队
				isvisited[i][j] = 1;//标记访问状态
			}
			else if (grid[i][j] == 1){
				cnt++;
			}
		}
	}
	
	if (q.empty() && cnt > 0)
		return -1;//初始状态就没有烂橘子， 只有好橘子
	else if (q.empty() && cnt == 0) //没有烂橘子也没有好橘子
		return 0;

	int ans = 0;
	int size = 0;
	while (!q.empty()){
		ans++;
		size = q.size();
		for (int j = 0; j<size; ++j){
			pair<int, int> p = q.front();
			//邻接节点
			for (int k = 0; k<4; k++){
				int x = p.first + dx[k];
				int y = p.second + dy[k];
				//越界,空,访问过
				if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()){
					if (grid[x][y] == 1 && !isvisited[x][y]){
						isvisited[x][y] = 1;
						q.push(make_pair(x, y));
						cnt--;
					}
				}
			}
			q.pop();
		}
	}
	return cnt ? -1 : ans - 1;
}

```
