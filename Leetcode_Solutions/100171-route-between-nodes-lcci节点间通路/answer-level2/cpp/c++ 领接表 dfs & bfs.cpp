250ms, dfs与bfs，这是最优解了，时间差异是评测机的问题
```c++
// dfs
class Solution {
public:
    bool dfs(int u, int target, vector<vector<int> >& e, vector<bool>* vis){
        (*vis)[u] = 1;
        for(auto v : e[u]){
            if(!(*vis)[v]) dfs(v, target, e, vis);
            if((*vis)[target]) return true;
        }
        return false;
    }
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int> > e(n);
        int u, v;
        // 创建领接表
        for(vector<int> edge : graph){
            u = edge[0], v = edge[1];
            e[u].push_back(v);
        }
        return dfs(start, target, e, new vector<bool>(n, false));
    }
};
```

```c++
// bfs

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int> > e(n);
        int u, v;
        for(vector<int> edge : graph){
            u = edge[0], v = edge[1];
            e[u].push_back(v);
        }

        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(auto v : e[u]){
                if(v == target) return true;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};
```