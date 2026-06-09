### 解题思路一

DFS，是一棵树如果满足：(1) 没有回边（除了回到parent视为同一条边以外）; (2) 只有一个联通分量（否则就是森林了）。

### 代码一

```cpp
class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges) {
      vector<bool> visited(n+1, false);
      if(edges.size() != n-1)
        return false;
      vector<vector<int>> E(n+1);
      for(int i=0; i<edges.size(); i++) {
        E[edges[i][0]].push_back(edges[i][1]);
        E[edges[i][1]].push_back(edges[i][0]);  // undirected graph
      }

      if (dfs(E, 0, visited, -1))
        return false;

      // maybe a forest
      for (int u = 0; u < n; u++)
        if (!visited[u])
          return false;

      return true;
    }

    // 如果有环则返回 true
    bool dfs(vector<vector<int>>& Edge, int v, vector<bool>& visited, int parent)
    {
      visited[v] = true;
      for (int i: Edge[v])
      {
        if (!visited[i])
        {
          if (dfs(Edge, i, visited, v))
            return true;
        }
        else if (i != parent)
          return true;
      }
      return false;
    }
};

```

### 解题思路二

BFS，需要保存的状态是一个pair，节点的子女及parent.

### 代码二
```cpp
class Solution {
  public:
    bool validTree(int n, vector<vector<int>>& edges) {
      unordered_set<int> visited;
      if(n == 1)
        return true;
      if(edges.size() != n-1)
        return false;
      vector<vector<int>> E(n+1);
      for(int i=0; i<edges.size(); i++) {
        E[edges[i][0]].push_back(edges[i][1]);
        E[edges[i][1]].push_back(edges[i][0]);  // undirected graph
      }

      if (bfs(E, 0, visited))
        return false;

      // maybe a forest
      if(visited.size() < n)
          return false;

      return true;
    }

    bool bfs(vector<vector<int>>& Edge, int v, unordered_set<int>& visited)
    {
      queue<pair<int, int>> q;   // record pair: <cur, parent>
      q.emplace(0, 0);
      
      while(!q.empty()) {
          auto r = q.front();
          q.pop();
          if(visited.find(r.first) != visited.end())
            return true;
          visited.insert(r.first);
          // cout << "Visiting " << r.first << " from " << r.second << endl;
          for(int i: Edge[r.first]) {
            if(i != r.second)
              q.emplace(i, r.first);
          }
      }
      return false;
    }
};
```
