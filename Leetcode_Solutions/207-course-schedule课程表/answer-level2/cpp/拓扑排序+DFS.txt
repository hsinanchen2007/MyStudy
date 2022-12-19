拓扑排序：
```cpp
class Solution
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<vector<int>> adjacenies(numCourses);		//邻接表，a->b
		vector<int> degrees(numCourses, 0);				//记录所有顶点的入度
		queue<int> degree_zero;							//记录入度为0的顶点
		/*初始化邻接表*/
		for (auto v : prerequisites)
		{
			degrees[v[0]]++;
			adjacenies[v[1]].push_back(v[0]);
		}
		int count = 0;			//记录入度为0的顶点数
		/*入度为0的顶点入队*/
		for (int i = 0; i < numCourses; ++i)
		{
			if (degrees[i] == 0)
			{
				degree_zero.push(i);
				count++;
			}
		}
		while (!degree_zero.empty())
		{
			int temp = degree_zero.front();
			degree_zero.pop();
			/*更新temp指向的节点，其入度-1*/
			for (auto n : adjacenies[temp])
			{
				if (--degrees[n] == 0)
				{
					degree_zero.push(n);
					count++;
				}
			}
		}
		return count == numCourses;
	}
};
```
DFS:
```cpp
class Solution
{
public:

	bool DFS(int x, vector<vector<int>> adjacenies, vector<int>& record)
	{
		/*说明再次回到了刚访问过的位置，即有环*/
		if (record[x] == 1)
		{
			return false;
		}
		/*说明之前已经有从别的节点DFS访问过了*/
		if (record[x] == 2)
		{
			return true;
		}
		record[x] = 1;
		for (auto n : adjacenies[x])
		{
			if (!DFS(n, adjacenies, record))
			{
				return false;
			}
		}
		record[x] = 2;
		return true;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<vector<int>> adjacenies(numCourses);		//邻接表，a->b
		/*初始化邻接表*/
		for (auto v : prerequisites)
		{
			adjacenies[v[1]].push_back(v[0]);
		}

		/*0:未被访问
		1:被当前节点的DFS访问过
		2:被其他节点DFS访问过*/
		vector<int> record(numCourses, 0);

		for (int i = 0; i < numCourses; ++i)
		{
			if (!DFS(i, adjacenies, record))
			{
				return false;
			}
		}
		return true;
	}
};
```