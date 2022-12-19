- 深搜即可
```cpp
class Solution {
public:
    int n;
    vector<vector<int>>res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int>temp;
        temp.push_back(0);
        dfs(graph,temp,0);
        return res;
    }
    void dfs(vector<vector<int>>& G,vector<int>&cur,int pos){
        if(cur.back()==n-1){
            res.push_back(cur);
            return ;
        }
        for(auto u:G[pos]){
            cur.push_back(u);
            dfs(G,cur,u);
            cur.pop_back();
        }
    }
};
```