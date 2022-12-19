```
class Solution {
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		/*
		1.首先遍历一遍edges,看看它是拥有2个爹还是拥有一个爹.
	      1)拥有一个爹,直接按684来写就行了,不多说.
	      2)拥有两个爹,这里假设 k 节点拥有2个爹, 返回的答案肯定是与这个节点和它爹相关的,那么我们只需要再次遍历edges,
		  找到 (第一个爹 , k)  (第二个爹 , k) 找到这类节点,把他们调整到edges 的末尾再按照684来写就行了.
		*/
		vector<int>parents_num(edges.size() + 1, 0);
		int k = -1;//k 是拥有2个爹的节点
		for (auto vi : edges) if (++parents_num[vi[1]] == 2)k = vi[1];

		if (k == -1)return solv1(edges);//如果只有一个爹,按684一样

		vector<pair<int, int>>temp;//临时存储 (爹 , k );

		vector<int>parents(edges.size() + 1);
		for (int i = 1; i <= edges.size(); ++i)parents[i] = i;
		//先跳过(爹 , k )节点
		for (auto vi : edges) {
			int x = vi[0], y = vi[1];
			if (y == k) {
				temp.push_back({ x,y });
				continue;
			}
			while (x != parents[x])x = parents[x];
			while (y != parents[y])y = parents[y];
			parents[x] = parents[y];
		}
		//最后再考虑(爹,k)节点相关的数据
		for (auto vi : temp) {
			int x = vi.first, y = vi.second;
			while (x != parents[x])x = parents[x];
			while (y != parents[y])y = parents[y];
			if (x == y)return { vi.first,vi.second };
			else parents[x] = parents[y];
		}
		return { temp.back().first,temp.back().second };
	}
	//只有一个爹的情况,直接按照684来写就行
	vector<int> solv1(vector<vector<int>>& edges) {
		vector<int>parents(edges.size() + 1);
		for (int i = 1; i <= edges.size(); ++i)parents[i] = i;
		for (auto vi : edges) {
			int x = vi[0], y = vi[1];

			while (x != parents[x])x = parents[x];
			while (y != parents[y])y = parents[y];
			if (x == y)return { vi[0],vi[1] };
			else parents[x] = parents[y];
		}
		return {};
	}
};
```