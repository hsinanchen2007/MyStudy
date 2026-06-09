### 广度优先搜索(BFS)/深度优先搜索(DFS)
1. 我们将服务器看作一个节点，在同一行和在同一列的节点连接，看作一个连通图。那么，这道题目就变成了计算***节点个数大于1的连通图的节点总数***。
2. 我们可以采用BFS/DFS遍历访问连通图即可。
```
class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int nCount = 0;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j]) {
					int nServer = bfsVisit(grid, i, j);
					nCount += (nServer > 1) ? nServer : 0;
				}
			}
		}
		return nCount;
	}

	// 计算连通图内服务器的个数，BFS和DFS都可以；
	// 可以添加一个bool数组，用来标记该位置是否被访问过
	// 这次就不用数组来标记了，直接把访问grid过程中的服务器改成0即可
	int bfsVisit(vector<vector<int>>& grid, int x, int y) {
		int nCount = 1;
		queue<pair<int, int>> bfsQueue;
		bfsQueue.push(make_pair(x, y));
		grid[x][y] = 0;
		while (!bfsQueue.empty()) {
			int x = bfsQueue.front().first;
			int y = bfsQueue.front().second;
			bfsQueue.pop();

			for (size_t i = 0; i < grid[x].size(); ++i) {
				if (grid[x][i]) {
					++nCount;
					bfsQueue.push(make_pair(x, i));
					grid[x][i] = 0;
				}
			}

			for (size_t i = 0; i < grid.size(); ++i) {
				if (grid[i][y]) {
					++nCount;
					bfsQueue.push(make_pair(i, y));
					grid[i][y] = 0;
				}
			}
		}

		return nCount;
	}
};
```
我果真不适合写题解，写文章啊！