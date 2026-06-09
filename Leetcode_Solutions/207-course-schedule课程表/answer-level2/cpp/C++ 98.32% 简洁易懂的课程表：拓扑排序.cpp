### 思路
![微信图片_20200314184607.png](https://pic.leetcode-cn.com/64e82d5ac77ae12a79db3075b2c26afdb65a9756f1d089c11da97eccd126e8c3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200314184607.png)

课程表问题是最典型的拓扑排序。故此处展示拓扑排序解法。
而这道题本质要判断的是：有向无权图中是否存在环。
因此，可以用拓扑排序判断有无环。
P.S.还可以用DFS来判断。
[https://blog.csdn.net/ywcpig/article/details/52599867]()
### 代码

```cpp
class Solution {
public:
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<int> indegree(numCourses);
	vector<vector<int>> graph(numCourses);//构建临接表（用vector储存临接点，方便访问）
	vector<int> v;
	for (int i = 0; i < numCourses; i++)
	{
		indegree[i] = 0;
		graph.push_back(v);
	}
	for (int i = 0; i < prerequisites.size(); i++)
	{
		indegree[prerequisites[i][0]]++;
		graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//存的是出边
	}
	//将入度为0的顶点入队
	queue<int> myqueue;
	for (int i = 0; i < numCourses; i++)
	{
		if (indegree[i] == 0)
			myqueue.push(i);
	}
	int cnt = 0;
	while (!myqueue.empty())
	{
		int temp = myqueue.front();
		myqueue.pop();
		cnt++;
		//更新：
		for (int i = 0; i < graph[temp].size(); i++)
		{
			indegree[graph[temp][i]]--;
			if (indegree[graph[temp][i]] == 0)//放在这里做！只判断邻接点。
				myqueue.push(graph[temp][i]);
		}		
	}
	return cnt == numCourses;

}
};
```