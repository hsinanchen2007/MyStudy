```
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> graph(n,vector<bool>(n,false));
        vector<bool> visit(n,false);
        queue<int> qu;
        
        for(auto e : edges){
            graph[e[0]][e[1]] = true;
            graph[e[1]][e[0]] = true;
        }
        
        qu.push(0);
        visit[0] = true;
        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            
            for(int i = 0;i < n; ++i){
                if(graph[curr][i]){
                    if(visit[i]){
                        return false;
                    }
                    visit[i] = true;
                    graph[curr][i] = false;
                    graph[i][curr] = false;
                    qu.push(i);
                }
            }
        }
        
        for(int i = 0;i < n; ++i){
            if(!visit[i]){
                return false;
            }
        }
        
        return true;
    }
};
```