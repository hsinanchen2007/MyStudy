Dijksta
```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int INF = 0x3f3f3f3f;
        int d[N+1],n=times.size(),res=0;
        bool used[N+1];
        vector<vector<int>>cost(N+1,vector<int>(N+1,INF));
        fill(d+1,d+N+1,INF);
        fill(used+1,used+N+1,false);
        for(int i=0;i<n;i++)cost[times[i][0]][times[i][1]]=times[i][2];
        d[K]=0;
        while(true){
            int v = -1;
            for(int u=1;u<=N;u++){
                if(!used[u] && (v==-1 || d[v]>d[u]))v=u;
            }
            if(v==-1)break;
            used[v]=1;
            for(int u=1;u<=N;u++){
                d[u] = min(d[u],d[v]+cost[v][u]);
            }
        }
        for(int i=1;i<=N;i++){
            if(d[i]==0x3f3f3f3f)return -1;
            res = max(res,d[i]);
        }
        return res;
    }
};
```
使用堆优化
```c++
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        struct edge {int to,cost;};
        typedef pair<int,int> P;
        vector<edge>G[N+1];
        const int INF = 0x3f3f3f3f;
        int d[N+1],n=times.size(),res=0;
        fill(d+1,d+N+1,INF);
        priority_queue<P,vector<P>,greater<P>>que;
        for(int i=0;i<n;i++){
            edge e;
            e.to = times[i][1];
            e.cost = times[i][2];
            G[times[i][0]].push_back(e);
        }
        d[K]=0;
        que.push({0,K});
        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first)continue;
            int len = G[v].size();
            for(int i=0;i<len;i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push({d[e.to], e.to});
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(d[i]==0x3f3f3f3f)return -1;
            res = max(res,d[i]);
        }
        return res;
    }
};
```
