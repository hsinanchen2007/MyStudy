```
class Solution {
public:
    vector<int> ans;
    vector<vector<int>> mp;
    bool vis[20001];//用来判断是否产生环
    int state[20001];//记录每个结点的状态（安全/非安全/未确定）
    vector<int> eventualSafeNodes(vector<vector<int>>& graphs) {
        mp = graphs;memset(state,-1,sizeof(state));
        for(int i=0;i<graphs.size();i++) dfs(i);
        for(int i=0;i<graphs.size();i++) if(state[i]) ans.push_back(i);
        return ans;
    }
    bool dfs(int num) {
        if(!mp[num].size()) return true;
        if(vis[num]) return state[num]=false;
        if(state[num]!=-1) return state[num];//已确定状态无须重复查找
        vis[num] = true;
        bool judge = true;
        for(auto& next: mp[num]) if(!dfs(next)) {judge=false;break;}//只要有环即不安全
        vis[num] = false;
        return state[num] = judge;
    }
};
```
