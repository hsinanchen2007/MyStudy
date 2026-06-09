每次找到上一批腐烂的橘子，然后计算下一批腐烂的橘子，知道下一批没有橘子腐烂，统计批数。最终检查所有橘子的状态，若存在新鲜橘子则返回-1，若根本没有橘子返回0，其他情况返回批数。
思路还是很清晰的，但是由于用set会对点排序，浪费运行时间，所以使用了unordered_set，就用出了大问题。
大问题是由在unordered_set中放入的是结构体导致的，一开始没写“==”的重载和对应hash函数的结构体，然后报了“尝试引用已被删除的函数”的错，好久没找到原因。
```C++ []
struct Point {
	int x, y;
	Point(int x1, int y1) : x(x1), y(y1) {}
};

bool operator==(const Point& X, const Point& Y)
{
	return (X.x == Y.x) && (X.y == Y.y);
}

struct Point_hash {
	size_t operator()(const Point& p) const {
		int tmp = p.x + p.y;
		return std::hash<int>()(tmp);
	}
};

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int count = -1;
		vector<vector<int>> tmp(grid);
		unordered_set<Point,Point_hash> rots;
		int n = grid.size(), m = grid[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {
					rots.insert(Point(i, j));
				}
			}
		}
		int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
		while (rots.size()) {	//rots中为最近一次腐烂的
			unordered_set<Point, Point_hash> rots2;
			count++;
			for (auto p:rots) {
				for (int i = 0; i < 4; i++) {
					int x = p.x + d[i][0];
					int y = p.y + d[i][1];
					if (x < 0 || x >= n || y < 0 || y >= m)
						continue;
					if (grid[x][y] != 1)
						continue;
					rots2.insert(Point(x, y));	//下一波要腐烂的
				}
			}
			for (Point p : rots2)
				grid[p.x][p.y] = 2;		//让它腐烂
			rots = rots2;	//将刚刚腐烂的放入rots
		}
		//若存在新鲜橘子则返回-1，若根本没有橘子返回0。
		bool flag = true;	//true表示没有橘子。
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}
				if (grid[i][j] == 2)
					flag = false;
			}
		}
		if (flag)
			return 0;
		return count;
	}
};
```
