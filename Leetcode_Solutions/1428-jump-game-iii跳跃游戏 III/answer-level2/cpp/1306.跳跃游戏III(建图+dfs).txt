### 解题思路
由题意,可以建立一张点数为$n$, 边数最多为$2n$的有向图,直接图上dfs即可.

### 代码

```cpp
class Solution {
public:
    int n;
    int used[50000];
    struct EDGE
    {
        int v,nxt;
    }edge[100000];
    int ecnt=0,fir[50000];
    void addedge(int u,int v)
    {
        edge[ecnt].v=v;
        edge[ecnt].nxt=fir[u];
        fir[u]=ecnt++;
    }
    void dfs(int u)
    {
        used[u]=1;
        for(int i=fir[u];i!=-1;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(!used[v])
                dfs(v);
        }
    }
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        if(n==0)
            return 0;
        memset(fir,-1,sizeof(fir));
        for(int i=0;i<n;i++)
        {
            int t1=i-arr[i],t2=i+arr[i];
            if(t1>=0)
                addedge(i,t1);
            if(t2<n)
                addedge(i,t2);
        }
        dfs(start);
        bool flag=0;
        for(int i=0;i<n;i++)
            if(arr[i]==0&&used[i]==1)
                flag=1;
        return flag;
    }
};
```