### 解题思路
设置两张访问表，从太平洋和大西洋边缘同时向内部递归，最后比较得出两张表的共同点即为所求。

### 代码

```cpp
class Solution {
private:
	vector<vector<int>> res;
	int m, n;
	int dis[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return {};

		m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>> pacific(m, vector<bool>(n, false));
		vector<vector<bool>> atlantic(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			dfs(matrix, pacific, INT_MIN, i, 0);
			dfs(matrix, atlantic, INT_MIN, i, n - 1);
		}
		for (int i = 0; i < n; ++i) {
			dfs(matrix, pacific, INT_MIN, 0, i);
			dfs(matrix, atlantic, INT_MIN, m - 1, i);
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (pacific[i][j] && atlantic[i][j]) {
					res.push_back({i, j});
				}
			}
		}
		return res;
	}
	void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int pre, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre) return;//规定水流只能从高到低或者在同等高度上流动。
		visited[i][j] = true;
		for (int k = 0; k < 4; k++) {
			int newx = i + dis[k][0];
			int newy = j + dis[k][1];
			dfs(matrix, visited, matrix[i][j], newx, newy);
		}
	}
};


```