```
class Solution {
public:
typedef pair<int,int> PII;
    //Dijkstra
   /* int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N+1,INT_MAX);
        vector<bool> vis(N+1,false);
        int res=INT_MIN;
        dist[K]=0;
        unordered_map<int,vector<pair<int,int>> >g;
        for(auto& t:times)
            g[t[0]].push_back({t[2],t[1]});
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        pq.push({0,K});
        while(!pq.empty()){
            auto u=pq.top().second;pq.pop();
            vis[u]=true;
            for(auto& nei:g[u]){
                int v=nei.second,w=nei.first;
                if(dist[u]+w>dist[v]||vis[v]) continue;
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
        res=*max_element(dist.begin()+1,dist.end());
        return res!=INT_MAX? res:-1;
    }*/
    //floyd
    /*int networkDelayTime(vector<vector<int>>& times, int N, int K){
        vector<vector<int>> dp(N+1,vector<int>(N+1,INT_MAX/2));
        int res=0;
        for(auto &t:times){
            dp[t[0]][t[1]]=t[2];
            dp[t[0]][t[0]]=dp[t[1]][t[1]]=0;
        }  
        for(int h=1;h<=N;h++){
            for(int u=1;u<=N;u++){
                for(int v=1;v<=N;++v)
                    dp[u][v]=min(dp[u][v],dp[u][h]+dp[h][v]);
            }
        }
        res=*max_element(dp[K].begin()+1,dp[K].end());
        return res!=INT_MAX/2? res:-1;
    }*/
    //bellman
    int networkDelayTime(vector<vector<int>>& times, int N, int K){
        vector<int> dp(N+1,101);
        dp[K]=0;
        for(int i=0;i<N;i++){
            for(auto& t:times){
                if(dp[t[1]]>dp[t[0]]+t[2])
                dp[t[1]]=dp[t[0]]+t[2];
            }
        }
        int res=*max_element(dp.begin()+1,dp.end());
        return res!=101?res:-1;   
    }
};
```
