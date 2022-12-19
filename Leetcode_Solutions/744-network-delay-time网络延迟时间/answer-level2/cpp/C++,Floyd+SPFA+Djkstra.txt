# Floyd
```
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res=0;
        vector<vector<int>>edge(N+1,vector<int>(N+1,0x3f3f));
        for(int i=1;i<=N;i++){//注意这里是从1开始的，因为我们下标是结点的值，结点值最小是1
            edge[i][i]=0;
        }
        for(auto v:times){
            edge[v[0]][v[1]]=v[2];
        }
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(edge[K][i]==0x3f3f)return -1;//如果不能使所有结点收到信号那么返回的是-1.
            res=max(res,edge[K][i]);
        }
        return res;

    }
};
```
# SPFA
```
class Solution {
public:
//SPFA解法
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        queue<int>que;
        vector<vector<int>>edge(N+1,vector<int>(N+1,INT_MAX));
        vector<int>dist(N+1,INT_MAX);//表示的是K点到其他结点的最短距离
        for(auto v:times){
            edge[v[0]][v[1]]=v[2];
        }
        que.push(K);
        dist[K]=0;
        //SPFA使用的是队列的方式存放中间结点，方便下一次更新
        while(!que.empty()){
            int x=que.front();
            que.pop();
            for(int i=1;i<=N;i++){//只要出现有边存在，同时边长度较小，那么更新边权值。同时将其放入队列中，下一次再更新一下，当没有边需要更新的时候，那么结束吧。。。
                if(edge[x][i]!=INT_MAX&&dist[x]+edge[x][i]<dist[i]){
                    dist[i]=dist[x]+edge[x][i];
                    que.push(i);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=N;i++){
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
```
# dijkstra
```
struct edge{
    int to;
    int cost;
};
typedef pair<int,int>P;

class Solution {
public:
//dijkstra算法，采用的是优先队列的小顶堆的特性，因为每一次更新会有一个结点的最短路径会最终的确定。那么下一次优先更新的是最小路径的结点。不需要每一次更新不同结点的距离。。。
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<edge>g[N+1];//数组中的形式是edge的格式
        int n=times.size();
        for(int i=0;i<n;i++){
            edge e;
            e.to=times[i][1];
            e.cost=times[i][2];
            g[times[i][0]].push_back(e);
        }
        set<int>vis;
        pq.push({0,K});
        int res=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(vis.count(x.second))continue;
            vis.insert(x.second);
            res=max(x.first,res);
            int n=g[x.second].size();
            for(int i=0;i<n;i++){
                edge v=g[x.second][i];
                if(vis.count(v.to))continue;
                pq.push({v.cost+x.first,v.to});
            }
        }
        return vis.size()==N?res:-1;
    }
};
```


