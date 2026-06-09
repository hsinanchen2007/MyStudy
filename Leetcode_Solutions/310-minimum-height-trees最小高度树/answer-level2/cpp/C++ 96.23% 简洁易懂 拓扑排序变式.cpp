# **思路**
![微信图片_20200314184607.png](https://pic.leetcode-cn.com/2480fbd2cf87788274b516f76375de96946fa6933c6871c0b6c431b39e77a1d0-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200314184607.png)

本题其实就是拓扑排序的变式。就是不断缩小图，直至剩下1、2个点，return。
然而，此题的变式点如下：
1. 本题为无向图，所以删除的点是入度为1的点。
2. 本题不能一个一个的删除入度为1的点，而应在一个循环中，一次性删除入度为1的点，使得以同样的速度缩小图，直至剩下<=2个点为止。


# **代码**
```
class Solution {
public:
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	if (n == 1)
		return { 0 };
	else if (n == 2)
		return{ 0,1 };

	vector<int> indegree(n);
	vector<vector<int>> graph(n);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		indegree[i] = 0;
		graph.push_back(v);
	}
	for (int i = 0; i < edges.size(); i++)
	{
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
		indegree[edges[i][0]]++;
		indegree[edges[i][1]]++;
	}
	queue<int> myqueue;
	for (int i = 0; i < n; i++)
	{
		if (indegree[i] == 1)
			myqueue.push(i);
	}
	int cnt = myqueue.size();//！！令cnt等于myqueue.size()，一次性将入度为1的点全部删去。
	while (n>2)
	{
		n -= cnt;//一次性将入度为一的点全部删去！！不能一个一个删！
		while (cnt--)
		{
			int temp = myqueue.front();
			myqueue.pop();
			indegree[temp] = 0;
			//更新：
			for (int i = 0; i < graph[temp].size(); i++)
			{
				if (indegree[graph[temp][i]] != 0)
				{
					indegree[graph[temp][i]]--;
					if (indegree[graph[temp][i]] == 1)//放在这里做！只判断邻接点。
						myqueue.push(graph[temp][i]);
				}
				
			}
		}
		cnt = myqueue.size();
	}
	vector<int> result;
	while (!myqueue.empty())
	{
		result.push_back(myqueue.front());
		myqueue.pop();
	}
	return result;
}
};
```
