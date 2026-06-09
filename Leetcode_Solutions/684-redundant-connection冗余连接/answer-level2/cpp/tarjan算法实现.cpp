### 解题思路

tarjan算法

### 代码

```cpp
class Solution {
public:
    vector<int> dfn,low;
    int cnt;
    stack<int> sta;
    unordered_map<int,vector<int>> um;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dfn.resize(n+1);low.resize(n+1);
        for(auto &i:edges){
            um[i[0]].push_back(i[1]);
            um[i[1]].push_back(i[0]);
        }
        cnt=1;
        dfs(1,-1);
        for(int i=n-1;i>=0;i--){
            if(low[edges[i][0]]==low[edges[i][1]])return edges[i];
        }
        return {};
    }
    int dfs(int a,int par){
        if(low[a]!=0){
            return low[a];
        }
        dfn[a]=low[a]=cnt++;
        sta.push(a);
        auto &tmp=um[a];
        for(auto &i:tmp){
            if(i!=par)low[a]=min(low[a],dfs(i,a));
        }
        if(low[a]==dfn[a]){
            while(sta.top()!=a){
                low[sta.top()]=dfn[a];
                sta.pop();
            }
            sta.pop();
        }
        return low[a];
    }
};
```