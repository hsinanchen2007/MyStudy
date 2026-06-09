### 解题思路
染色法

### 代码

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        bool flag = true;//表示是二分图
        for(int i = 0;i < n;++i){
            if(!color[i]){
                if(!dfs(color, graph, i, 1)){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return true;
        return false;
    }
    bool dfs(vector<int>& color, vector<vector<int> >& g,int u, int c){
        color[u] = c;
        for(int i = 0;i < g[u].size();++i){
            int t = g[u][i];
            if(color[t] == c) return false;
            if(!color[t] && !dfs(color, g, t, 3-c)) return false;
        }
        return true;
    }
};
```