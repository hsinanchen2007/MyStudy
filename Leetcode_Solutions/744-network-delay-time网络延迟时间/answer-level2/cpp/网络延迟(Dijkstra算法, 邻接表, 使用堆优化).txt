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
        int pos,dist; //该节点下标, 该节点到源节点的距离
        Edge* first=NULL;  //依附该节点的第一条边
        bool operator> (const Node& n)const {return dist>n.dist;};
    };

    int networkDelayTime(vector<vector<int>>& times, int N, int src) 
    {
        vector<Node> Nodes(N+1); //所有节点
        for(int i=1;i<=N;i++) Nodes[i]=Node{i,INF};

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
        Nodes[src].dist=0;
        priority_queue<Node,vector<Node>,greater<Node>> q;
        q.push(Nodes[src]);

        vector<int> ac(N+1,0);  //ac=1是已确定的节点

        while(!q.empty())
        {
            int w=q.top().pos;
            q.pop();
            if(ac[w]) continue;
            ac[w]=1;

            for(Edge* e=Nodes[w].first; e ;e=e->next)
            {
                if(Nodes[e->to].dist > Nodes[w].dist + e->power)  
                {
                    Nodes[e->to].dist = Nodes[w].dist + e->power;
                    q.push(Nodes[e->to]);     
                }
            }
        }

        int end_time=0;
        for(int i=1;i<=N;i++)
        {
            if(Nodes[i].dist==INF) return -1;
            if(Nodes[i].dist>end_time) end_time=Nodes[i].dist; 
        }

        return end_time;
    }
};
```