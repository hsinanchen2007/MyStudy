- 拿到题的第一想法就是转化成有向图(管理指向下属即manger[i]->i)再用Dijkstra求解,然后看下数据范围是$10^5$,普通的dijkstra肯定超时,所以用堆优化到$O(nlgn)$的复杂度
- a了之后发现非常慢所以这个做法肯定不够好,再思考了一下就可以发现这道题其实只要求从源点到每个节点中的距离最大值就行了,而且代码很简洁。
```c++
\**
    优化版Dijkstra
**\
class Solution {
public:
    struct edge{
        int to,cost;
    };
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        typedef pair<int,int> P;
        vector<edge>G[n];
        vector<bool>used(n,false);
        vector<int>d(n,0x3f3f3f3f);
        int res=0;
        for(int i=0;i<n;++i){
            if(manager[i] != -1){
                edge e;
                e.to = i;
                e.cost = informTime[manager[i]];
                G[manager[i]].push_back(e);
            }
        }
        priority_queue<P,vector<P>,greater<P>>que;
        d[headID]=0;
        que.push({0,headID});
        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first)continue;
            for(auto &c:G[v]){
                edge e = c;
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push({d[e.to], e.to});
                }
            }
        }        
         for(int i=0;i<n;++i){
            res = max(res,d[i]);
        }
        return res;
    }
};
```
\**
    dfs版
**\
- dfs做法
cur记录当前最大值，ans记录全局最大值
```c++
class Solution {
public:
    struct edge{
        int to,cost;
    };
    vector<vector<edge>>G;
    int cur,ans;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        G = vector<vector<edge>>(n);
        for(int i=0;i<n;++i){
            if(manager[i] != -1){
                edge e;
                e.to = i;
                e.cost = informTime[manager[i]];
                G[manager[i]].push_back(e);
            }
        }
        dfs(headID);
        return ans;
    }
    void dfs(int u){
        int m = G[u].size();
        for(int i=0;i<m;++i){
            edge e = G[u][i];
            cur += e.cost;
            ans = max(ans,cur);
            dfs(e.to);
            cur -= e.cost;
        }
    }
};
```