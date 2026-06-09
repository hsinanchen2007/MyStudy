可以发现，对于做完操作的最终局面来说，从(0,0)开始的路径是确定的，每个点只能按一个方向来走。
那么问题就变为，对于每个点，选择一个方向，若此方向与初始方向不同，代价为1。
对于化简后的问题，每个点向相邻的点连边，对应方向的代价为边权，直接跑最短路即可。

为什么这么做是对的？我们这样建模得到的图中任意一条路径，对应着图上一条路径，且方向是定的，最短路相邻点直接的边就是原图每个点的“方向”，所以很显然是对的。
时间复杂度：O(nmlog(nm))，空间复杂度：O(nm)

注意到边权只有1和0，所以可以用双端队列进行优化，将时间复杂度的log去掉（不过我比赛时直接拍板子没这么干）。

```
class Solution {
    int n,m;
    int num(int x,int y) {return x*m+y;}
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    const int INF=1<<30;
    struct node
    {
        int x,v;
        node () {} ;node (int _x,int _v) {x=_x;v=_v;}
        bool operator < (const node &t) const {return v>t.v;}
    };
public:
    int minCost(vector<vector<int>>& A) {
        n=A.size();
        m=A[0].size();
        int S=num(0,0);
        int T=num(n-1,m-1);
        vector<vector<pair<int,int> > > To(n*m);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
            {
                --A[i][j];
                for (int k=0;k<4;++k)
                {
                    int tx=i+dx[k];
                    int ty=j+dy[k];
                    if (tx<0 || tx>=n || ty<0 || ty>=m) continue;
                    To[num(i,j)].emplace_back(num(tx,ty),(int)(k!=A[i][j]));
                }
            }
        vector<int> dis(20000,INF);
        vector<bool> flag(20000,false);
        priority_queue<node> Q;
        dis[S]=0;
        Q.push(node(S,0));
        while (!Q.empty())
        {
            node x=Q.top();Q.pop();
            if (flag[x.x] || dis[x.x]!=x.v) continue;
            if (x.x==T) break;
            flag[x.x]=true;
            for (int i=0;i<To[x.x].size();++i)
            {
                int to=To[x.x][i].first;
                int v=To[x.x][i].second;
                if (!flag[to] && dis[to]>x.v+v)
                {
                    dis[to]=x.v+v;
                    Q.push(node(to,dis[to]));
                }
            }
        }
        return dis[T];
    }
};
```
