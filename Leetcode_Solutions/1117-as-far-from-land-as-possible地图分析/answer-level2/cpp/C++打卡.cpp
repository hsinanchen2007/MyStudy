### 解题思路
看大佬们的题解学习了多源BFS，找到最大的搜索深度，即为最大的距离

### 代码

```cpp
struct coord {
	int x, y;
};


class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
		int row = grid.size(), col = grid.at(0).size();

		queue<coord>myQueue;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid.at(i).at(j) == 1) {
					myQueue.push({ i,j });
				}
			}
		}
		if (myQueue.size() == 0 || myQueue.size() == row * col) { return -1; }

		int minDis = 0;
		while (myQueue.empty() == false) {
			int count = myQueue.size();
			while (count) {
				coord cur = myQueue.front();
				myQueue.pop();
				count--;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir], ny = cur.y + dy[dir];
					if (nx<0 || nx>row - 1 || ny<0 || ny>col - 1) { continue; }
					else {
						if (grid.at(nx).at(ny) == 0) {
							grid.at(nx).at(ny) = 2;
							myQueue.push({ nx,ny });
						}
					}
				}

			}
			minDis++;
		}
		return minDis-1;	
	}
};
```