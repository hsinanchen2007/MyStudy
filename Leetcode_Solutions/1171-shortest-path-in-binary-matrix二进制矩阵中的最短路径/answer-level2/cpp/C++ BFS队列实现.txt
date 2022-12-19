### 解题思路
BFS队列实现。熟悉后，BFS用队列，DFS用栈，操作都差不多。

### 代码

```cpp
struct P{ // 定义点，二维中通常就 x,y,d(depth)这三项
	int x;
	int y;
	int d;
	P(int x=0, int y=0, int d=0):x(x),y(y),d(d){}
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int N = grid.size();
		if(grid[0][0] == 1 || grid[N-1][N-1] == 1)
			return -1;
		
		// 方向集合
		int D[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,1},{1,1},{1,0}, {1,-1},{0,-1}};
		vector<vector<int>> visited(N, vector<int>(N, 0));//是否访问过该位置
		
		queue<P> q; // bfs标配
		q.push(P(0,0,1)); // (0,0): depth = 1
		visited[0][0] = 1;
		
		P p; // 当前访问的点
		while( !q.empty()) {
			p = q.front(); // 队列首元素
			q.pop();//出队列
			
			if(p.x == N-1 && p.y == N-1) //到达右下角
				break;
				
			for(int i=0; i<7; i++) {
				int x2 = p.x + D[i][0];
				int y2 = p.y + D[i][1];
				x2 = max(0, min(x2, N-1)); //边界判断，0 <= x2 <= N-1
				y2 = max(0, min(y2, N-1)); // 0 <= y2 <= N-1
				if( !visited[x2][y2] && grid[x2][y2] == 0) { // 未访问且不是障碍
					q.push(P(x2, y2, p.d + 1));//入队
					visited[x2][y2] = 1;//已访
				} 
			}	
		}
		
		if(p.x == N-1 && p.y == N-1) // 判断有没有成功到达右下角
			return p.d;
		else
			return -1;
    }
};
```