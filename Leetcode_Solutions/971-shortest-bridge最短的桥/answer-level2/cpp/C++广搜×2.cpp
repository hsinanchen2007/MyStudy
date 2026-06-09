### 解题思路
写了半天，思路简单，实现嘛要哑巴吃饺子-心中有数。
1. 先找到一个小岛一部分，广搜找到整座小岛。把整座小岛的位置加入一个队列。
2. 用一个和$grid$维度一致的数组来看当前位置是否访问过。
3. 从一个小岛扩展开，直到找到另一个小岛。
4. 为了计算距离，首先找到的小岛的深度$level=0$，每向外扩展一步，$level=当前level+1$。

### 代码

```cpp

struct P {
	int x;
	int y;
	int v;
    P(int x=0, int y=0, int v=0) : x(x), y(y), v(v){}
};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
		int level = 0;
		int m = A.size();
		int n = A[0].size();
		vector<vector<int>> visited(m, vector<int>(n, 0));
		queue<P> qu1, qu2;
		// qu1 用来找到小岛1
		// qu2 用来扩展到小岛2

		bool goon = true;
		for(int i=0; i<m && goon; i++) {
			for(int j=0; j<n && goon; j++) {
				if(A[i][j] == 1) { 			// 找到小岛1一角
					qu1.push(P(i, j, 0)); 	// 深度均为0
					visited[i][j] = 1;
					goon = false;
				}
			}
		}
		
		while(!qu1.empty()) { 	// 按图索骥，访问完整个小岛1，即把小岛1的visited设置为1
			P cp = qu1.front();	// cp 取 current point 之意
			qu2.push(cp); 		// qu2保存了整个小岛1的位置
			
			qu1.pop();
			// 下面4个if分别访问上下左右4个位置
			if(cp.x > 0 && !visited[cp.x-1][cp.y] && A[cp.x-1][cp.y]==1) {	
				qu1.push(P(cp.x-1, cp.y, 0));
				visited[cp.x-1][cp.y] = 1;
			}
			if(cp.x < m-1 && !visited[cp.x+1][cp.y] && A[cp.x+1][cp.y]==1) {
				qu1.push(P(cp.x+1, cp.y, 0));
				visited[cp.x+1][cp.y] = 1;
			}
			if(cp.y > 0 && !visited[cp.x][cp.y-1] && A[cp.x][cp.y-1]==1) {	
				qu1.push(P(cp.x, cp.y-1, 0));
				visited[cp.x][cp.y-1] = 1;
			}
			if(cp.y < n-1 && !visited[cp.x][cp.y+1] && A[cp.x][cp.y+1]==1) {
				qu1.push(P(cp.x, cp.y+1, 0));
				visited[cp.x][cp.y+1] = 1;
			}
		}
		

		while(!qu2.empty()) { // 向外扩展，直到找到小岛2
			P cp = qu2.front(); 
			qu2.pop();
			
			level = cp.v; // level 的计算方法，取出当前节点的level
			
			// 下面4个if分别访问上下左右4个位置
			if(cp.x > 0 && !visited[cp.x-1][cp.y]) {
				if(A[cp.x-1][cp.y] == 1)
					break;		
				qu2.push(P(cp.x-1, cp.y, level+1)); // 此处 level+1
				visited[cp.x-1][cp.y] = 1;
			}
			if(cp.x < m-1 && !visited[cp.x+1][cp.y]) {
				if(A[cp.x+1][cp.y] == 1)
					break;
				qu2.push(P(cp.x+1, cp.y, level+1));// 此处 level+1
				visited[cp.x+1][cp.y] = 1;
			}
			if(cp.y > 0 && !visited[cp.x][cp.y-1]) {
				if(A[cp.x][cp.y-1] == 1)
					break;	
				qu2.push(P(cp.x, cp.y-1, level+1));// 此处 level+1
				visited[cp.x][cp.y-1] = 1;
			}
			if(cp.y < n-1 && !visited[cp.x][cp.y+1]) {
				if(A[cp.x][cp.y+1] == 1)
					break;
				qu2.push(P(cp.x, cp.y+1, level+1));// 此处 level+1
				visited[cp.x][cp.y+1] = 1;
			}
			
		}
		
		return level;
    }
};

```