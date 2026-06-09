```
class Solution {
public:
//执行用时 :120 ms, 在所有 C++ 提交中击败了96.30%的用户
//内存消耗 :31.3 MB, 在所有 C++ 提交中击败了90.32%的用户
    int n;
    int min_quiet[500];//存储比此结点更有钱的最小安静结点
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n = quiet.size();memset(min_quiet,-1,sizeof(min_quiet));
        vector<int> ans(n);
        vector<vector<int>> mp(n,vector<int>());
        for(auto& it: richer) mp[it[1]].push_back(it[0]);
        for(int i=0;i<n;i++) ans[i] = dfs(i,quiet,mp);
        return ans;
    }
    int dfs(int vex,vector<int>& quiet,vector<vector<int>>& mp) {
        if(!mp[vex].size()) return vex;
        if(min_quiet[vex]!=-1) return min_quiet[vex];
        int min_val = quiet[vex];int rec=vex;
        for(auto& v: mp[vex]) {
            int num = dfs(v,quiet,mp);
            if(quiet[num]<min_val) min_val=quiet[num],rec=num;
        }
        return min_quiet[vex] = rec;
    }
};
```
