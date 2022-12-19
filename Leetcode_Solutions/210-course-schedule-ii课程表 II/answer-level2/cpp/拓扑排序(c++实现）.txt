- 用二维向量实现一个邻接表adjList。每一个表项均由一个向量组成，我们规定表项的第一个单元用来存放该节点的入度(初始化时已经置为零)，其后的单元用来存放该结点的后继节点。
- 对传递来的向量进行遍历，初始化邻接表
- 定义队列，遍历邻接表，对度为0的节点入队
- 队首元素出队，入ret向量，队首元素的后继节点的入度减一并判断是否0，为0则入队
- 重复上一步，直到队为空
- 判断ret的大小，如果大小为numCources，则证明找到了一种排列方式；否则图中有环，没有满足的方案，清空之后返回。
```
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> adjList(numCourses, vector<int>{0});
		for (auto i : prerequisites) {
			adjList[i[0]][0]++;
			adjList[i[1]].push_back(i[0]);
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (!adjList[i][0])
				q.push(i);
		}
		vector<int> ret;
		while (!q.empty()) {
			auto v = q.front();
			q.pop();
			ret.push_back(v);
			if (adjList[v].size() > 1) {
				for (int i = 1; i < adjList[v].size(); i++) {
					auto w = adjList[v][i];
					adjList[w][0]--;
					if (!adjList[w][0])
						q.push(w);
				}
			}
		}
		if (ret.size() == numCourses)
			return ret;
		ret = {};
		return ret;
	}
};
```
