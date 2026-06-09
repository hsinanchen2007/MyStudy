### 解题思路
题意为让找出图中最长路径

### 代码

```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int> > graph(n, vector<int>());
        for(int i = 0 ; i < manager.size() ; ++i)
        {
            if(manager[i] == -1)
                continue;
            graph[manager[i]].push_back(i);
        }
        DFS(headID, 0, graph, informTime);
        return ans;
    }
    void DFS(int node, int sum, vector<vector<int> > &graph, vector<int>& informTime)
    {
        if(graph[node].size() == 0)
        {
            ans = max(ans, sum);
            return ;
        }
        for(int i = 0 ; i < graph[node].size() ; ++i)
        {
            DFS(graph[node][i], sum + informTime[node], graph, informTime);
        }
    }
private:
    int ans = 0;
};
```