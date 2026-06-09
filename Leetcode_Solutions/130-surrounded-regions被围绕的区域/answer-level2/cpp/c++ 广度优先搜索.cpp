简单的bfs，遇到`O`，就放入到队列中，搜索过程中，遇到边界就终止
bfs过程中，注意避免重复访问
代码写的很长，不过一次就过了
```
//找到所有被'X'包围的区域
void solve(vector<vector<char>>& board) {
	//广度优先搜索 //若遇到'O'//将其放入队列中// 
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 'O') {
				board[i][j] = '?';
				vector<pair<int, int>> pos;
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				pos.push_back({ i,j });
				bool valid = true;
				while (!Q.empty()) {
					pair<int, int> p = Q.front();
					Q.pop();
					int i = p.first;
					int j = p.second;
					if (i - 1 < 0 || i + 1 >= board.size() || j - 1 < 0 || j + 1 >= board[0].size()) {
						valid = false;
						break;
					}
					//避免重复访问
					if (board[i - 1][j] == 'O') {
						Q.push({ i - 1,j });
						pos.push_back({ i - 1,j });
						board[i - 1][j] = '?';
					}
					if (board[i][j + 1] == 'O') {
						Q.push({ i,j + 1 });
						pos.push_back({ i,j + 1 });
						board[i][j + 1] = '?';
					}
					if (board[i + 1][j] == 'O') {
						Q.push({ i + 1,j });
						pos.push_back({ i + 1,j });
						board[i + 1][j] = '?';
					}
					if (board[i][j - 1] == 'O') {
						Q.push({ i,j - 1 });
						pos.push_back({ i,j - 1 });
						board[i][j - 1] = '?';
					}
				}
				if (valid) {
					for (int i = 0; i < pos.size(); i++) {
						int x = pos[i].first;
						int y = pos[i].second;
						board[x][y] = 'X';
					}
				}
				else {
					for (int i = 0; i < pos.size(); i++) {
						int x = pos[i].first;
						int y = pos[i].second;
						board[x][y] = 'O';
					}
				}
				pos.clear();
			}
		}
	}
}
```