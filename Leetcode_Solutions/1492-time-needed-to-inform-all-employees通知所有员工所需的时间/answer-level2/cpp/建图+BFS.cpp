建立图结构，朴素的BFS,结果为最后一个人接到通知的时间
```
typedef pair<int,int> ii;
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> edge(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                edge[manager[i]].push_back(i);
        }
        queue<ii> q;
        q.push(ii{headID,0});
        int res=0;
        while(!q.empty()){
            auto u=q.front();q.pop();
            res=max(res,u.second);
            for(int nb:edge[u.first]){
                q.push(ii{nb,u.second+informTime[u.first]});
            }
        }
        return res;
    }
};
```
