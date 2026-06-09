### 算法简介
建图的时候边权为该边点数+1，建好图之后跑一遍最短路算法，就可以知道哪些点是可以到达的。在可以到达的点上还有$M-dist[i]$的剩余步数，这样的步数可以在它周围的边上走这么多步。
1. 统计哪些大点可以到达，加入ans
2. 统计每条边上的小点，根据其两侧端点的剩余步数之和加入ans

### 代码

```
const int N = 3010;
const int M = 10010;

class Solution {
public:
    
    int h[N],e[M*2],ne[M*2],w[M*2],idx;
    int st[N], q[N], dist[N];
    
    void add(int a,int b,int c)
    {
        e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    }
    
    void spfa()
    {
        memset(dist,0x3f,sizeof dist);
        int hh = 0, tt = 1;
        q[0] = 0;
        dist[0] = 0;
        while(hh != tt) {
            int t = q[hh++];
            if(hh == N) hh = 0;
            st[t] = false;
            
            for(int i = h[t] ; ~i ; i = ne[i]) {
                int j = e[i];
                if(dist[j] > dist[t] + w[i]) {
                    dist[j] = dist[t] + w[i];
                    
                    if(!st[j]) {
                        q[tt++] = j;
                        if(tt==N) tt = 0;
                        st[j] = true;
                    }
                }
            }
        }
    }
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        memset(h,-1,sizeof h);
        for(auto x:edges)
            add(x[0],x[1],x[2]+1),
            add(x[1],x[0],x[2]+1);
        
        spfa();
        int ans = 0;
        for(int i = 0 ; i < N ; i++)
            ans += dist[i] <= M;
        
        for(auto x:edges) {
            int t = 0;
            if(dist[x[0]] <= M) t += M-dist[x[0]];
            if(dist[x[1]] <= M) t += M-dist[x[1]];
            ans += min(t,x[2]);
        }
        return ans;
    }
};
```