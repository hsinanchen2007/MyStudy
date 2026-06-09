
寻找到各个节点最短路的最大值，建图跑Dijkstra算法，使用优先队列进行优化。

```c++ []
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<HeapNode> pq;
        vector<int> total_cost(N+1, INT_MAX/2);
        vector<bool> vis(N+1, false);
        
        init(N);
        for(auto it : times){
            addEdge(it[0], it[1], it[2]);
        }
        
        pq.push(HeapNode{K, 0});
        total_cost[K] = 0;
        
        while(pq.size()){
            auto now = pq.top();
            pq.pop();
            int u = now.node;
            if(vis[u]) continue;
            vis[u] = true;
            for(int v = 0;v < G[u].size();++v){
                Edge& edge = edges[G[u][v]];
                if(total_cost[edge.to] > total_cost[u] + edge.cost){
                    total_cost[edge.to] = total_cost[u] + edge.cost;
                    pq.push(HeapNode{edge.to, total_cost[edge.to]});
                }
            }
        }
        int max_val = *max_element(total_cost.begin()+1, total_cost.end());
        return max_val == INT_MAX/2 ? -1 : max_val;
    }
private:
    struct Edge{
        int from, to, cost;
        Edge(int u, int v, int t):from(u),to(v),cost(t){}
    };
    struct HeapNode{
        int node, cost;
        bool operator<(const HeapNode& rhs) const {
            return cost > rhs.cost;
        }
    };
    static const int maxn = 101;
    vector<int> G[maxn];
    vector<Edge> edges;
    
    void init(int n){
        for(int i = 1;i <= n;i++) G[i].clear();
        edges.clear();
    }
    
    void addEdge(int from, int to, int cost){
        edges.emplace_back(from, to, cost);
        G[from].push_back(edges.size()-1);
    }
};
```