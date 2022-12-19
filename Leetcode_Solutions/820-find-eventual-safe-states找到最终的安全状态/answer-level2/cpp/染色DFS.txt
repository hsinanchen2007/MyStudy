```
class Solution {
public:
    //染色：0表示未访问，-1表示不安全，1表示安全
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> g(graph.size(),0);
        function<bool(int)> dfs=[&](int index){
            if(g[index]!=0)
                return g[index]==1;
            g[index]=-1;//先假设不安全
            for(auto &nei:graph[index]){
                if(!dfs(nei)) return false;
            }         
            g[index]=1;
            return true;
        };
        vector<int> res;
        for(int i=0;i<graph.size();++i){
            if(g[i]==1) res.push_back(i);
            else if(g[i]==0&&dfs(i)) res.push_back(i);
        }  
        return res;
    }
};
```
