写着玩的，耗时表现不好，空间倒是100%了

```cpp
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n, vector<int>(0));
        vector<vector<int>> result;
        vector<int> dfn(n, 0);
        vector<int> first(n, 0);
        vector<int> parent(n, 0);
        vector<bool> visited(n, false);
        vector<pair<int, int>> stack;
        stack.clear();
        for(int i = 0; i < connections.size(); i++)
        {
            edges[connections[i][0]].push_back(connections[i][1]);
            edges[connections[i][1]].push_back(connections[i][0]);
        }
        int now = 0;
        stack.push_back(make_pair(now, 0));
        visited[0] = true;
        while(1)
        {
            if(stack.back().second == edges[stack.back().first].size())
            {
                stack.pop_back();
                if(stack.size() <= 0)
                    break;
                continue;
            }
            if (visited[edges[stack.back().first][stack.back().second]])
            {
                if (first[edges[stack.back().first][stack.back().second]] > dfn[stack.back().first])
                    result.push_back({ stack.back().first, edges[stack.back().first][stack.back().second] });
                if (first[edges[stack.back().first][stack.back().second]] < first[stack.back().first] && parent[stack.back().first] != edges[stack.back().first][stack.back().second])
                    first[stack.back().first] = first[edges[stack.back().first][stack.back().second]];
                ++stack.back().second;
            }
            else
            {
                visited[edges[stack.back().first][stack.back().second]] = true;
                dfn[edges[stack.back().first][stack.back().second]] = ++now;
                first[edges[stack.back().first][stack.back().second]] = now;
                parent[edges[stack.back().first][stack.back().second]] = stack.back().first;
                stack.push_back(make_pair(edges[stack.back().first][stack.back().second], 0));
            }           
        }
        return result;
    }
};
```

