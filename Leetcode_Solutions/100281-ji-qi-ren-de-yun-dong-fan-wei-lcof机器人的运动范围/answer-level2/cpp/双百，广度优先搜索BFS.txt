### 解题思路
搜索起点：(0,0) 搜索方向：右和下
使用一个二维数组记录该点是否被搜索过，使用队列来记录待搜索的点位置

### 代码

```cpp
 class Solution {
 public:
	 struct _pos
	 {
		 int x, y;
	 };
	 int movingCount(int m, int n, int k) {
		 //广度优先搜索，BFS
		 int sum = 0;
		 queue<_pos> q;
		 q.push({ 0,0 });
		 vector<vector<int>> vis(m, vector<int>(n, 0));
		 while (!q.empty())
		 {
			 _pos pos = q.front();
			 q.pop();

			 if (pos.x / 10 + pos.x % 10 + pos.y / 10 + pos.y % 10 > k)
				 continue;
			 sum++;
			 if (pos.x + 1 < m && vis[pos.x + 1][pos.y] == 0)
			 {
				 q.push({ pos.x + 1,pos.y });
				 vis[pos.x + 1][pos.y] = 1;
			 }
			 if (pos.y + 1 < n && vis[pos.x][pos.y + 1] == 0)
			 {
				 q.push({ pos.x,pos.y + 1 });
				 vis[pos.x][pos.y + 1] = 1;
			 }
		 }
		 return sum;
	 }
 };

```