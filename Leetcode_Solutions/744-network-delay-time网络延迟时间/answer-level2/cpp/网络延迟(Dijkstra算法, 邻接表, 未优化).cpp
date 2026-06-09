### 解题思路

### 代码

```cpp
class Solution 
{
public:
    const int INF=1<<10;

    struct Edge  //边结构
    {
        int to,power;  //该边指向的顶点的下标，边权
        Edge* next=NULL;   //下个边
    };

    struct Node //节点结构
    {
        int dist; //该节点到源节点的距离
        Edge* first=NULL;  //依附该节点的第一条边
    };

    int networkDelayTime(vector<vector<int>>& times, int N, int src) 
    {
        vector<Node> Nodes(N+1,Node{INF}); //所有节点

        for(int i=0;i<times.size();i++)
        {
            Edge* e=new Edge{times[i][1],times[i][2]};

            if(Nodes[times[i][0]].first)
            {
                Edge* last=Nodes[times[i][0]].first;
                while(last->next) last=last->next;
                last->next=e;
            }  
            else Nodes[times[i][0]].first=e;
        }

        return Dijkstra(Nodes,N,src);
    }

    int Dijkstra(vector<Node>& Nodes,int N,int src)
    {
        vector<int> ac(N+1,0);  //ac=1的是已确定的点
        Nodes[src].dist=0;
        
        int end_time=0,flag=0;

        while(flag<N)  //也可用 for(int i=1;i<=N;i++)
        {
            int min=INF,w; //w为待确定的点(wait to accept)

            for(int j=1;j<=N;j++)
                if(!ac[j] && min>Nodes[j].dist)
                    min=Nodes[j].dist,w=j;

            ac[w]=1,flag++;

            for(Edge* e=Nodes[w].first; e ;e=e->next)
                if(Nodes[e->to].dist > Nodes[w].dist + e->power)
                    Nodes[e->to].dist = Nodes[w].dist + e->power;             
        }

        for(int i=1;i<=N;i++)
        {
            if(Nodes[i].dist==INF) return -1;
            if(Nodes[i].dist>end_time) end_time=Nodes[i].dist; 
        }

        return end_time;
    }
};
```