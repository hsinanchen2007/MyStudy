- 邻接表 BFS

```cpp
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    	bool visited[n] = {false};
    	visited[start] = true;
    	vector<vector<int>> map(n);
    	int i, tp;
    	for(i = 0; i < graph.size(); ++i)
    	{
    		map[graph[i][0]].push_back(graph[i][1]);
    	}
    	queue<int> q;
    	q.push(start);
    	while(!q.empty())
    	{
    		tp = q.front();
    		if(tp == target)
    			return true;
    		q.pop();
    		for(i = 0; i < map[tp].size(); ++i)
    		{
    			if(!visited[map[tp][i]])
    			{
    				q.push(map[tp][i]);
    				visited[map[tp][i]] = true;
    			}
    		}
    	}
    	return false;
    }
};
```
![在这里插入图片描述](https://pic.leetcode-cn.com/c70664e4c86542765d239475a735a5ded5604c4c2d929f3b440d097eb937e7c5.png)
- 邻接表 DFS
```cpp
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    	bool visited[n] = {false};
    	visited[start] = true;
    	vector<vector<int>> map(n);
    	for(int i = 0; i < graph.size(); ++i)
    	{
    		map[graph[i][0]].push_back(graph[i][1]);
    	}
    	bool found = false;
    	dfs(map,start,target,found,visited);
    	return found;
    }

    void dfs(vector<vector<int>>& map , int start, int& target, bool& found, bool* visited)
    {
    	if(start == target)
    		found = true;
    	if(found)
    		return;
    	for(int i = 0; i < map[start].size(); ++i)
    	{
    		if(!visited[map[start][i]])
    		{
    			visited[map[start][i]] = true;
    			dfs(map,map[start][i],target,found,visited);
    			visited[map[start][i]] = false;
    		}
    	}
    }
};
```
![在这里插入图片描述](https://pic.leetcode-cn.com/2078c7e9dde64cf521ee04adf1fa2e9372a4226d0e276484ee0f5173a10ce139.png)