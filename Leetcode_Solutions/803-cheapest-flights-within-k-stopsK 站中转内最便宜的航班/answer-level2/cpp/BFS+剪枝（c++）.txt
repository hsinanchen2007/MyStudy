### 解题思路
1.用BFS列出所有K步以内的路径，过程中若到达目的点则更新res,并且终止当前路径的往下搜索。
2.但是直接BFS会超时，所以需要剪枝。用一个数组记录每个节点当前的最小花费，每次路径搜索到当前节点时只有比当前最小花费更小的时候才有必要走到这个节点（因为前面记录的最小花费同时消耗的步数也比当前步数更小（或相等），因此没有必要再往当前节点走），否则终止。

### 代码

```cpp
class Solution {
public:
    struct node{
        int current;
        int cost;
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> edge(n,vector<int>(n,0));
        int len=flights.size();
        for(int i=0;i<len;i++)
        {
            edge[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        queue<node> q;
        int res=INT_MAX;
        node start;
        start.current=src;
        start.cost=0;
        q.push(start);
        K++;
        vector<int> node_min(n,INT_MAX);
        while(K--&&!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                node cur=q.front();
                q.pop();
                int cur_index=cur.current;
                int cur_cost=cur.cost;
                for(int j=0;j<n;j++)
                {
                    if(edge[cur_index][j]>0&&cur_cost+edge[cur_index][j]<node_min[j])
                    {
                        if(j==dst&&cur_cost+edge[cur_index][j]<res)
                        {
                            res=cur_cost+edge[cur_index][j];
                            continue;
                        }
                        node_min[j]=cur_cost+edge[cur_index][j];
                        node next;
                        next.current=j;
                        next.cost=cur_cost+edge[cur_index][j];
                        q.push(next);
                        
                    }
                }
            }
        }
        return res>100000?-1:res;
    }
};
```