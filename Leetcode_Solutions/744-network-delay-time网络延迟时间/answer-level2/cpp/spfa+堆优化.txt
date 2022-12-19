### 解题思路
本质是求源点到各结点的最短路中最长的那一条

### 代码

```cpp
class Solution {
public:
    struct Node{
        int v, w;
        Node(int _v, int _w) : v(_v), w(_w){}   //构造函数
        friend bool operator<(Node a, Node b)
        {
            return a.w > b.w;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<Node>> graph(N + 1, vector<Node>());
        for(int i = 0 ; i < times.size() ; ++i)
        {
            graph[times[i][0]].push_back(Node(times[i][1], times[i][2]));
        }
        int d[N + 1] = {0}; //num数组记录顶点的入队次数
        fill(d, d + N + 1, INF);
        bool inq[N + 1] = {false};   //顶点是否在队列中
        priority_queue<int> q;
        q.push(K);
        inq[K] = true; 
        d[K] = 0;
        while(!q.empty())
        {
            int u = q.top();
            q.pop();
            inq[u] = false;
            for(int i = 0 ; i < graph[u].size() ; ++i)
            {
                int dis = graph[u][i].w;
                int v = graph[u][i].v;
                if(d[u] + dis < d[v])
                {
                    d[v] = d[u] + dis;
                    if(!inq[v])
                    {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        for(int i = 1 ; i <= N ; ++i)
        {
            if(i == K)
                continue;
            if(d[i] == INF)
                return -1;
            ans = max(d[i], ans);
        }
        return ans;
    }
private:
    int ans = 0;
    int INF = 0x3f3f3f3f;
};
```