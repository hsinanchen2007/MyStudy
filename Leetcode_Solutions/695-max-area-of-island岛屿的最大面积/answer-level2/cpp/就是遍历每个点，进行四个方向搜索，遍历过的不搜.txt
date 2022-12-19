用于grid同样大小的flag数组记录对应点是否被搜索过
二重循环遍历每个点，对于所有值为1的且没被搜过的点，进行四周搜索。
搜索过程可以递归可以非递归，下面代码用的非递归，用队列进行了广度优先搜索，只要是值为1的且没被搜过的点就加入队列，出队时对该点标记为搜索过，并且该岛屿面积加一。
找到所有岛屿中面积最大的就是题目要求的值。

PS：以前有一段时期一直做动态规划的题，导致看到题就想进行动态规划，直到碰到一道和这题类似的题，才发现使用动态规划的一个最基本条件，就是计算好的值是不能再进行改动的，也就是说后面计算出的值不能影响前面计算好的值。虽然以前也知道动态规划必须给计算的东西进行拓扑排序，但理解还不到位。比如这种对于四个方向扩散的，是没有方向性的，构成的图存在环，没法进行拓扑排序。

```C++ []
struct Point {
	int x, y;
	Point(int x1, int y1) : x(x1), y(y1) {}
};

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), true));
		int max = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] && flag[i][j]) {
					int count = cal_islands_area(i, j, grid, flag);
					max = max > count ? max : count;
				}
			}
		}
		return max;
	}

	int cal_islands_area(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& flag) {
		int count = 0;
		queue<Point> q;
		q.push(Point(i, j));
		flag[i][j] = false;

		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		while (!q.empty()) {
			count++;
			Point tmp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = tmp.x + dx[i], y = tmp.y + dy[i];
				if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] && flag[x][y]) {
					q.push(Point(x, y));
					flag[x][y] = false;
				}
			}
		}
		return count;
	}
};
```
