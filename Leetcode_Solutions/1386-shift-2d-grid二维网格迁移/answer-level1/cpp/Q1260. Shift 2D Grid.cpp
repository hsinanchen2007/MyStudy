### 双向队列
1. 先将二维网格线性成一维的双向队列
2. 执行k次操作：将双向队列的最后一个数字压入到队列的前面，弹出队列内的最后一个数字；
3. 最后将一维的双向队列重新转换成二维的网格即可。
```
class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		deque<int> dequeGrid;
		for (size_t i = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {
				dequeGrid.push_back(grid[i][j]);
			}
		}
		for (int i = 0; i < k; ++i) {
			int nBack = dequeGrid.back();
			dequeGrid.pop_back();
			dequeGrid.push_front(nBack);
		}

		for (size_t i = 0, k = 0; i < grid.size(); ++i) {
			for (size_t j = 0; j < grid[i].size(); ++j) {
				grid[i][j] = dequeGrid.at(k++);
			}
		}

		return grid;
	}
};
```
