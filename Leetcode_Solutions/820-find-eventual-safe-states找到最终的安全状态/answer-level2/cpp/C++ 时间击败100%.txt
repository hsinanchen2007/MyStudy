```
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int len=graph.size();
        if(len==0) {
            return res;
        }
        vector<bool> vis(len, false);
        vector<int> cnt(len, -1);
        for(int i=0;i< len;i++) {
            if(cnt[i]==-1) {
                vis[i]=true;
                dfs(i,vis, cnt, graph);
                vis[i]=false;
            }
        }
        for(int i=0;i<len;i++) {
            if(cnt[i]==1) {
                res.push_back(i);
            }
        }
        return res;
    }
    bool dfs(int id, vector<bool>& vis, vector<int>& cnt, vector<vector<int>>& graph) {
        if(cnt[id]!=-1) { // 记忆化搜索，否则超时！
            return cnt[id]==0;
        }
        bool found_circle=false;
        for(int i=0;i<graph[id].size();i++) {
            if(vis[graph[id][i]]||cnt[graph[id][i]]==0) {
                found_circle=true;
                break;
            }
            vis[graph[id][i]]=true;
            found_circle=dfs(graph[id][i],vis, cnt, graph);
            if(found_circle) {
                break;
            }
            vis[graph[id][i]]=false;
        }
        if(!found_circle) {
            cnt[id]=1;
        }else {
            cnt[id]=0;
        }
        return cnt[id]==0;
    }
};
```
