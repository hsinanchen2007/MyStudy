```
const int maxn=1e4;
class Solution {
public:
    vector<int>g[maxn];
    void dfs(vector<int>&vis,int i){
        vis[i]=1;
        for(auto v:g[i]){
            if(!vis[v]){
                dfs(vis,v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n=r.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<r[i].size();j++){
                g[i].push_back(r[i][j]);
            }
        }
        vector<int>vis(maxn,0);
        dfs(vis,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
```