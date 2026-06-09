## 广度优先搜索BFS/深度优先搜索DFS
BFS/DFS搜索并标记连通图岛屿，如果该岛屿在地图的四边上，则该岛屿不是封闭的。
```
class Solution {
public:
	int closedIsland(vector<vector<int>>& grid) {
		int dir[4][2] = {
			{0, -1},	// left
			{-1, 0},	// top
			{0, 1},		// right
			{1, 0}		// bottom
		};

		int nCount = 0;
		deque<pair<int, int>> bfsDeque;

		// 可以在搜索的过程中直接将grid地图中0变成1进行标记的；
		// 另外借助二维数组flag只是为了方便理解。
		vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] || flag[i][j])
					continue;

				bool isClosed = true;
				bfsDeque.clear();
				bfsDeque.push_back(make_pair(i, j));
				flag[i][j] = true;
				while (!bfsDeque.empty()) {
					pair<int, int> cell = bfsDeque.front();
					bfsDeque.pop_front();

					// update isClosed flag
					if (isClosed) {
						if (cell.first == 0 || cell.first == grid.size() - 1 ||
							cell.second == 0 || cell.second == grid[i].size() - 1) {
							isClosed = false;
						}
					}

					// 4 directions
					for (int k = 0; k < 4; ++k) {
						size_t iRow = cell.first + dir[k][0];
						size_t iCol = cell.second + dir[k][1];
						if (iRow >= 0 && iRow < grid.size() &&
							iCol >= 0 && iCol < grid[i].size() &&
							!grid[iRow][iCol] && !flag[iRow][iCol]) {
							bfsDeque.push_back(make_pair(iRow, iCol));
							flag[iRow][iCol] = true;
						}
					}
				}

				nCount += (isClosed ? 1 : 0);
			}
		}

		return nCount;
	}
};
```
我果真不适合写题解，写文章啊！