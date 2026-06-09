### 解题思路
最小高度为直径的一半，所以可以转化为求直径，根节点就是直径的中心

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> g;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>>(n, vector<int>{});
        for(auto t : edges){ 
            g[t[0]].push_back(t[1]); 
            g[t[1]].push_back(t[0]);
        }
        vector<int> path = path_bfs(bfs(0));
        int t = path.size();
        cout << t << endl;
        if(t % 2) return {path[t/2]};
        return {path[t/2-1], path[t/2]};
    }
    int bfs(int u){
        queue<int> q;
        q.push(u);
        vector<int> state(g.size(),false);
        int res = -1;
        while(q.size()){
            res = q.front();q.pop();
            state[res] = true;
            for(auto t : g[res]){
                if(!state[t]) q.push(t);
            }
        }
        return res;
    }
    vector<int> path_bfs(int u){
        queue<int> q;
        q.push(u);
        vector<int> state(g.size(),false);
        vector<int> pre(g.size(),-1);
        int t;
        while(q.size()){
            t = q.front();q.pop();
            state[t] = true;
            for(auto p : g[t]){
                if(!state[p]){
                    q.push(p);
                    pre[p] = t;
                }
            }
        }
        vector<int> path;
        while(t != -1){
            path.push_back(t);
            t = pre[t];
        }
        return path;
    }
};
```