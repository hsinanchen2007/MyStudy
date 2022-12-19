### 解题思路
dfs染色问题

### 代码

```cpp
class Solution {
public:
    void DFS(vector<vector<int>>& graph, int i, vector<int>& color, int current_color, bool &res){
        if(color[i] != 0 or res == false) return;
        color[i] = current_color;
        for(auto n:graph[i]){
            if(color[n]!=0 and color[n] == current_color){
                res = false;
                return;
            }
            DFS(graph, n, color, -current_color, res);
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),0);
        bool res = true;
        for(int i =0;i<graph.size();i++){
            DFS(graph, i, color, 1, res);
        }
        return res;
    }
};
```