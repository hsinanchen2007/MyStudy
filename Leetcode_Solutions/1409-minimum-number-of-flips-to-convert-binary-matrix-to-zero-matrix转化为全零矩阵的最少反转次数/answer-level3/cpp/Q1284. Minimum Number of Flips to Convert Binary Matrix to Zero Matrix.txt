### 广度优先搜索 + 位压缩
&emsp;&emsp;将矩阵`matrix`的状态看作一个节点，一次反转操作看作是到另外一个状态节点的边，长度等于1。那么该题就变成了求从初始状态节点`mat`到目标状态节点`0`的最短路径了。因此，该题使用广度优先搜索`BFS`求解。

&emsp;&emsp;中心算法已经得出来了，但是还有一个小问题，`BFS`的过程中需要记录哪些状态节点被记录过，直接使用矩阵`matrix`会很不方便。对于题设范围这么小(`3*3`)的二进制矩阵，我采用的是位压缩的形式，将二进制矩阵转换成一个整数。整数`0 ~ m*n-1`即各个状态节点。

&emsp;&emsp;将矩阵转换成整数还有一个好处，就是做反转操作的时候，可以直接对相应的`bit`位取反即可。整数`N`对第`k`位取反的位运算是：`N = N ^ (1 << k)`。
```
class Solution {
public:
	typedef int State;
	enum { TargetState= 0 };

public:
	int minFlips(vector<vector<int>>& mat) {
		State initState = transMatToState(mat);
		if (initState == TargetState)
			return 0;

		size_t m = mat.size();
		size_t n = mat[0].size();

		queue<pair<State, unsigned int>> bfsQueue;
		unordered_map<State, bool> mapFliped;
		bfsQueue.push(make_pair(initState, 0));
		mapFliped[initState] = true;
		while (!bfsQueue.empty()) {
			pair<State, unsigned int> frontItem = bfsQueue.front();
			bfsQueue.pop();

			for (size_t i = 0; i < m; ++i) {
				for (size_t j = 0; j < n; ++j) {
					State newState = flipMat(frontItem.first, m, n, i, j);
					if (newState == TargetState)
						return frontItem.second + 1;

					if (!mapFliped[newState]) {
						bfsQueue.push(make_pair(newState, frontItem.second + 1));
						mapFliped[newState] = true;
					}
				}
			}
		}

		return -1;
	}

	// 将Matrix转换成整数State，方便map
	State transMatToState(vector<vector<int>>& mat) {
		State st = 0;
		for (size_t i = 0; i < mat.size(); ++i) {
			for (size_t j = 0; j < mat[i].size(); ++j)
				st = st * 2 + mat[i][j];
		}
		return st;
	}

	// 翻转(x,y)及其相邻的单元格
	State flipMat(State state, size_t m, size_t n, size_t x, size_t y) {
		// 反转(x,y)
		size_t p = x * n + y;
		state ^= (1 << p);

		// 反转(x-1,y)
		if (x > 0) {
			p = (x - 1) * n + y;
			state ^= (1 << p);
		}

		// 反转(x+1,y)
		if (x < m - 1) {
			p = (x + 1) * n + y;
			state ^= (1 << p);
		}

		// 反转(x, y-1)
		if (y > 0) {
			p = x * n + y - 1;
			state ^= (1 << p);
		}

		// 反转(x,y+1)
		if (y < n - 1) {
			p = x * n + y + 1;
			state ^= (1 << p);
		}

		return state;
	}
};
```
我果真不适合写题解，写文章啊！