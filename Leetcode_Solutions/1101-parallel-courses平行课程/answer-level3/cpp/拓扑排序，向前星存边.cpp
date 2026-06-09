题中说一次可以学习全部没有依赖的课程，意味着一次可以将所有入度为0的点入队列，那么所花费的学期数就是1次，因此可以令$t$为队列的size，在全部出队并将相应入度减完后，++ans，如果队列中仍有剩余，会继续这个过程，直到没有入度为0的点为止，注意要加一个$cnt$计数，观察入队列的点的总数是多少，如果总数是$<n$的，说明有环，并不是DAG，不存在拓扑排序，输出-1。
前面是无前驱的拓扑排序方法，同样的，也可以将上面的入度换成出度，就是无后继的拓扑排序方法，输出为逆序的排序，当然这题不需要输出，所以是一样的。
```
const int N=5005;
struct edge{
    int v,next;
}G[N];
int in[N],vertex[N];
class Solution {
public:
    int tot,n;
    void addedge(int u,int v){
        G[tot].v=v,G[tot].next=vertex[u],vertex[u]=tot;
        ++in[v],++tot;
    }
    int topsort(){
        int q[n],head=0,tail=0,cnt=0;
        for(int i=1;i<=n;++i){
            if(!in[i]){
                q[tail++]=i;
                ++cnt;
            }
        }
        int ans=0;
        while(head<tail){
            int t=tail-head;
            while(t--){
                for(int i=vertex[q[head++]];~i;i=G[i].next){
                    int v=G[i].v;
                    if(!--in[v]){
                        q[tail++]=v;
                        ++cnt;
                    }
                }
            }
            ++ans;
        }
        return cnt==n?ans:-1;
    }
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        tot=0,n=N;
        memset(vertex,-1,sizeof vertex);
        memset(in,0,sizeof in);
        for(auto &i:relations)addedge(i[0],i[1]);
        return topsort();
    }
};
```
