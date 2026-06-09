### 解题思路
首先因为是无向树，所以添加边的时候正反都应该加一下。
在初始化树之后进行深度最深为t的深度搜索就可以了。
要注意的是这只青蛙死脑筋，不走回头路的，所以每次跳的时候都要重新计算一下有几条边可以跳。


### 代码

```cpp
class Solution {
public:

	void addEdge(int start, int end, vector<vector<int>>& tree) {
		if (0 == tree[start][0]) {
			tree[start][0] = end;
		}
		else {
			int ptr = tree[start][0];
			while (tree[start][ptr]) {
				ptr = tree[start][ptr];
			}
			tree[start][ptr] = end;
		}
	}

	//t ==> lave times
	double deepSearch(const vector<vector<int>>& tree, map<int, bool>& pathMap, int t, int pos, int target, double p) {
		if (t == 0) {
			if (pos == target) {
				return p;
			}
			return 0;
		}
		
		int edgeNum = 0;
		int next = tree[pos][0];
		while (next != 0) {
			if (!pathMap[next]) {
				edgeNum++;
			}
			next = tree[pos][next];
		}
		if (edgeNum == 0) {
			if (pos == target) {
				return p;
			}
			return 0;
		}
		next = tree[pos][0];
		while (next != 0) {
			int newTarget = next;
			next = tree[pos][next];
			if (pathMap[newTarget]) {
				continue;
			}
			pathMap[newTarget] = true;
			double np = deepSearch(tree, pathMap, t - 1, newTarget, target, p / edgeNum);
			pathMap[newTarget] = false;
			if (np != 0) {
				return np;
			}
		}
		return 0;
	}

	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		int size = n + 1;
		vector<vector<int>> tree;
		map<int, bool> pathMap;
		pathMap[1] = true;
		for (int i = 0; i <= n; ++i) {
			tree.push_back(vector<int>(n + 1));
		}
		for (const auto& edge : edges) {
			addEdge(edge[0], edge[1], tree);
			addEdge(edge[1], edge[0], tree);

		}
		return deepSearch(tree, pathMap, t, 1, target, 1);
	}
};
```