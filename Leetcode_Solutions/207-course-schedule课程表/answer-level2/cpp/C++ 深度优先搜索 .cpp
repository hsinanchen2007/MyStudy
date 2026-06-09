```
class Solution {
public:
    bool dfs(vector<vector<int> >& graph, vector<int>& status, int i) {
        if (status[i] == 2)
            return true;
        if (status[i] == 1)
            return false;
        status[i] = 1;
        for (auto j : graph[i])
            if (!dfs(graph, status, j))
                return false;
        status[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> status(numCourses, 0);
        vector<vector<int> > graph(numCourses, vector<int>{});
        for (auto& e : prerequisites)
            graph[e[1]].push_back(e[0]);
        for (int i = 0; i < numCourses; ++i)
            if (!dfs(graph, status, i))
                return false;
        return true;
    }
};
```

