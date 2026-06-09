### 解题思路
- BFS 队列遍历，用visit记录从该节点以某种颜色出发是否被访问
- 每个节点用`pair<int,int>`记录节点和最近边访问的颜色

### 代码

```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ans(n, -1);
		ans[0] = 0;
		vector<vector<int> > redAdj(n), blueAdj(n);
		for (auto e : red_edges)redAdj[e[0]].push_back(e[1]);
		for (auto e : blue_edges)blueAdj[e[0]].push_back(e[1]);
		queue<pair<int,int>> q;
		q.push(make_pair(0, 0)), q.push({ 0,1 });
		vector<vector<bool> > visited(n, vector<bool>(2, false));
		int dis = 0;
		while(!q.empty())
		{
			dis++;
			int width = q.size();
			for(int _=0;_<width;_++)
			{
				const auto p = q.front();
				q.pop();
				if (p.second == RED)
				{
					for (int next : blueAdj[p.first])
					{
						if (!visited[next][BLUE])
						{
							visited[next][BLUE] = true;
							if (ans[next] == -1)ans[next] = dis;
							q.push({ next,BLUE });
						}
					}
				}
				else
				{
					for (int next : redAdj[p.first])
					{
						if (!visited[next][RED])
						{
							visited[next][RED] = true;
							if (ans[next] == -1)ans[next] = dis;
							q.push({ next,RED });
						}
					}
				}
			}	
		}
		return ans;
    }
private:
	enum color { RED=0,BLUE=1 };
    //const int inf = INT_MAX;
};
```