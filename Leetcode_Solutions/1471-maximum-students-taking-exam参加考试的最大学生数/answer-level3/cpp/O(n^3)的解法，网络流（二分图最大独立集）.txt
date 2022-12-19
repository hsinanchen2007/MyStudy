大家都在说DP，这里介绍一种可处理更大数据范围的方法，网络流。首先我们只关心可以坐人的座位，我们把作为按照列下标的奇偶建二分图，S向奇数下标的座位连边，偶数下标的座位向T连边，有冲突的座位奇数座位向偶数座位连边。图中所有边流量都是1。直接跑二分图最大点独立集就行，即可以坐人的座位数-最大流。
时间复杂度：O(n^3) 空间复杂度：O(n^2)
![QQ图片20200214215921.png](https://pic.leetcode-cn.com/49fbbc776cd4d8678ba00a3c76a6a02f5bd9037973b9f04cf9c34a9b6f62e685-QQ%E5%9B%BE%E7%89%8720200214215921.png)

```
class Solution {
    const int INF=1<<29;
    int tot,head[110];
    struct Edge {int to,net,v;}E[10010];
    void addedge(int x,int y,int v)
    {
        E[++tot].to=y;E[tot].net=head[x];head[x]=tot;E[tot].v=v;
        E[++tot].to=x;E[tot].net=head[y];head[y]=tot;E[tot].v=0;
    }
    int n,m,S,T,Q[110],depth[110];
    int getp(int x,int y)
    {
        return x*m+y+1;
    }
    bool bfs()
    {
        for (int i=S;i<=T;++i) depth[i]=-1;
        int L=0,R=1;
        Q[1]=S;
        depth[S]=0;
        while (L<R)
        {
            int x=Q[++L];
            for (int i=head[x];i;i=E[i].net)
                if (E[i].v>0 && depth[E[i].to]==-1)
                {
                    depth[E[i].to]=depth[x]+1;
                    Q[++R]=E[i].to;
                }
        }
        return depth[T]!=-1;
    }
    int dfs(int x,int flow)
    {
        if (x==T || !flow) return flow;
        int w=0;
        for (int i=head[x];i;i=E[i].net)
            if (E[i].v>0 && depth[E[i].to]==depth[x]+1)
            {
                int v=dfs(E[i].to,min(flow-w,E[i].v));
                E[i].v-=v;E[i^1].v+=v;w+=v;
            }
        if (!w) depth[x]=-1;
        return w;
    }
    int Dinic() {int sum=0;while(bfs()) sum+=dfs(S,INF);return sum;}
public:
    int maxStudents(vector<vector<char>>& seats) {
        tot=1;
        n=seats.size();
        m=seats[0].size();
        S=0;
        T=n*m+1;
        int cnt=0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                if (seats[i][j]=='.')
                {
                    ++cnt;
                    int x=i*m+j+1;
                    if (j&1) addedge(S,x,1);
                    else addedge(x,T,1);
                    if (j-1>=0 && seats[i][j-1]=='.')
                    {
                        if (j&1) addedge(x,getp(i,j-1),1);
                        else addedge(getp(i,j-1),x,1);
                    }
                    if (j+1<m && seats[i][j+1]=='.')
                    {
                        if (j&1) addedge(x,getp(i,j+1),1);
                        else addedge(getp(i,j+1),x,1);
                    }
                    if (i && j+1<m && seats[i-1][j+1]=='.')
                    {
                        if (j&1) addedge(x,getp(i-1,j+1),1);
                        else addedge(getp(i-1,j+1),x,1);
                    }
                    if (i && j && seats[i-1][j-1]=='.')
                    {
                        if (j&1) addedge(x,getp(i-1,j-1),1);
                        else addedge(getp(i-1,j-1),x,1);
                    }
                }
        return cnt-Dinic();
    }
};
```
