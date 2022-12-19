```
class Solution {
public:
    bool dfs(int curr,vector<bool> & visit,vector<vector<bool>> &graph){
        bool res = true;
        visit[curr] = true;

        for(int i = 0;i < graph.size(); ++i){
            if(graph[curr][i]){
                if(visit[i]){
                    return false;
                }
                visit[i] = true;
                graph[curr][i] = false;
                graph[i][curr] = false;
                res &= dfs(i,visit,graph);
            }
        }
        return res;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> graph(n,vector<bool>(n,false));
        vector<bool> visit(n,false);
        bool ans = false;
        
        for(auto e : edges){
            graph[e[0]][e[1]] = true;
            graph[e[1]][e[0]] = true;
        }
        
        ans = dfs(0,visit,graph);
        for(int i = 0;i < n; ++i){
            if(!visit[i]){
                return false;
            }
        }
        
        return ans;
    }
};
```