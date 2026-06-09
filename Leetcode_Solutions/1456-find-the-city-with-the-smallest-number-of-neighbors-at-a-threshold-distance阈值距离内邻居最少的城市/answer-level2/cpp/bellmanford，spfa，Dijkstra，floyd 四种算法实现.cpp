

---------------时间--空间
bellmanford：--5%----100%
spfa：---------30%---100%
Dijkstra：-----23%---100%
floyd：--------40%---100%
### 代码

```cpp
const int N = 1100, M = N*(N-1)/2 + 20;
//方法一：bellmanford写法
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int, int> ans(0x3f3f3f, -1);//first表示满足的城市个数，second 代表城市起点
        int dist[N];
        int last[N];
        memset(dist,0x3f,sizeof dist);
        //建立无向图
        int t = edges.size();
        for(int i = 0;i < t;++i){
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            edges.push_back({b,a,w});
        }
        //贝尔曼福特求最短距离,枚举每个起点
        for(int k = 0;k < n;++k){
            dist[k] = 0;
            int cnt = 0;//统计满足距离小于阈值的城市个数
            for(int j = 0;j < n-1;++j){
                memcpy(last, dist, sizeof dist);
                for(int i = 0;i < edges.size();++i){
                    int a = edges[i][0], b = edges[i][1], w = edges[i][2];
                    dist[b] = min(dist[b], last[a] + w);
                }
            }
            for(int i = 0;i < n;++i)
                if(dist[i] <= distanceThreshold) ++cnt;
            if(cnt < ans.first){ 
                ans.second = k;
                ans.first = cnt;
            }
            if(cnt == ans.first) ans.second = k;
            memset(dist, 0x3f,sizeof dist);
        }
        return ans.second;
    }
};
//方法二：spfa
class Solution{
    public:
    int h[N], w[M], e[M], ne[M], idx;
    int dist[N];
    bool flag[N];
    int v;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int, int> ans(0x3f3f3f, -1);//first表示满足的城市个数，second 代表城市起点
        v = n;
        memset(h, -1, sizeof h);
        //建图
        for(int i = 0;i < edges.size();++i){
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            add(a, b, w), add(b, a, w);
        }
        //枚举每个起点，分别求出dist数组
        for(int i = 0;i < n;++i){
            memset(dist, 0x3f, sizeof dist);
            memset(flag, false, sizeof flag);
            int cnt = 0;
            spfa(i);
            //dist数组求出之后按照题意处理
            for(int j = 0;j < n;++j)
                if(dist[j] <= distanceThreshold) ++cnt;
            if(cnt < ans.first){ 
                ans.second = i;
                ans.first = cnt;
            }
            if(cnt == ans.first) ans.second = i;
        }
        return ans.second;
    }
    void add(int a, int b, int c){
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    }
    void spfa(int u){
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()){
            int t = q.front(); q.pop();
            flag[t] = false;            
            for(int i = h[t];i != -1;i = ne[i]){
                int j = e[i];
                if(dist[j] > dist[t] + w[i]){
                    dist[j] = dist[t] + w[i];
                    if(!flag[j]) q.push(j);
                    flag[j] = true;
                }
            }
        }
    }
};
//方法三：dijkstrak
class Solution{
    public:
    int h[N], w[M], e[M], ne[M], idx;
    int dist[N];
    bool flag[N];
    int v;
    typedef pair<int, int> PII;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int, int> ans(0x3f3f3f, -1);//first表示满足的城市个数，second 代表城市起点
        v = n;
        memset(h, -1, sizeof h);
        //建图
        for(int i = 0;i < edges.size();++i){
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            add(a, b, w), add(b, a, w);
        }
        //枚举每个起点，分别求出dist数组
        for(int i = 0;i < n;++i){
            memset(dist, 0x3f, sizeof dist);
            memset(flag, false, sizeof flag);
            int cnt = 0;
            dijkstra(i);
            //dist数组求出之后按照题意处理
            for(int j = 0;j < n;++j)
                if(dist[j] <= distanceThreshold) ++cnt;
            if(cnt < ans.first){ 
                ans.second = i;
                ans.first = cnt;
            }
            if(cnt == ans.first) ans.second = i;
        }
        return ans.second;
    }
    void add(int a, int b, int c){
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    }
    void dijkstra(int u){
        priority_queue<PII, vector<PII>, greater<PII> > pq;
        dist[u] = 0;
        pq.push({0, u});
        while(!pq.empty()){
            auto t = pq.top();pq.pop();
            int d = t.first, v = t.second;
            if(flag[v])continue;
            flag[v] = true;
            for(int i = h[v];i != -1;i = ne[i]){
                int j = e[i];
                if(dist[j] > w[i] + d){
                    dist[j] = d + w[i];
                    pq.push({dist[j], j});
                }
            }
        }
    }
};
//方法四：floyd
class Solution{
    public:
    int v;
    int d[N][N];
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        pair<int, int> ans(0x3f3f3f, -1);//first表示满足的城市个数，second 代表城市起点
        v = n;
        //init
        for(int i = 0;i < v;++i)
            for(int j = 0;j < v;++j)
                if(i == j)d[i][j] = 0;
                else d[i][j] = 0x3f3f3f3f;
        //建图
        for(int i = 0;i < edges.size();++i){
            int a = edges[i][0], b = edges[i][1], w = edges[i][2];
            d[a][b] = w, d[b][a] = w;
        }
        floyd();
        //d数组求出之后按照题意处理
        for(int i = 0;i < n;++i){
            int cnt = 0;
            for(int j = 0;j < n;++j)
                if(d[i][j] <= distanceThreshold){
                    ++cnt;
                }
            if(cnt < ans.first){ 
                ans.second = i;
                ans.first = cnt;
            }
            if(cnt == ans.first) ans.second = i;
        }
        return ans.second;
    }
    void floyd(){
        for(int k = 0;k < v;++k)
            for(int i = 0;i < v;++i)
                for(int j = 0;j < v;++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
};














```