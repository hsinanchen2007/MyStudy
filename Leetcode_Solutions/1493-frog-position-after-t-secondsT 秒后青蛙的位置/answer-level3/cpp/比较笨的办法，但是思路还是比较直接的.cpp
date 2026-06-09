## 思路
我的思路是这样的：从源点一路跳到目的点target，这一路上每一次面对分叉，青蛙都需要做选择。选择某一条路走的概率，就是这一点的分叉数的倒数。因此到达target这一点的概率就是从原点到target的路径上每一点的分叉数之积的倒数。不过这些点可不包括target，毕竟它到了target就可以不用继续跳了（但是青蛙比较笨，如果有路还是会跳，这个就留给后面进行特判好了）。
## 实现思路
首先先构建一个图，这一点是很简单的，因为图的顶点数和边集都给好了。我选择用邻接矩阵建图(我使用了**vector<vector<int>>**，其实 **vector<list<int>>** 也是可以的)。
建完图之后再建一颗树，这棵树用一个数组表示，tree[i]就是结点i的父亲(parent)的编号，如果父亲(parent)的编号为-1说明i为根结点。
有了这个图和树之后就可以从target这一点一直往回推了，推到根结点便可停下来，这一路上到达的每个点的分叉数其实就是这个点的度减一（因为父亲不算进分叉数），不过根结点要特殊处理，因为根结点没有父亲。而点i的度(degree)就是**G[i].size()** 。
算完分叉数之积后，就要进行判断了，如果返回的路径长度length比t大，那注定是没戏的，因为时间都不够青蛙跳到那里去。如果路径比t小，而且根结点后面还有路可以跳，那也是没戏的（笨青蛙）。如果target就是根结点且根结点后面有路可以走，而t又大于0，那也是没戏的。之所以还要判断这种情况，是因为第二种情况没有考虑target为根结点的情况，只需补上第三种就可以了。
## 代码
```
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) 
    {        
        vector<vector<int>> G(n+1); // 无向图
        vector<int> tree(n+1, -1); // 树，每个结点记录它的父亲(parent)，如果父亲(parent)为-1说明为根结点
        for(int i=0;i<edges.size();i++) //建图
        {
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }             

        // 使用BFS建树
        queue<int> Q;
        Q.push(1);
        while(!Q.empty())
        {         
            int s = Q.front(); Q.pop();
            for(int i=0;i<G[s].size();i++)
                if(G[s][i] != tree[s])
                {
                    tree[G[s][i]] = s;
                    Q.push(G[s][i]);
                }
        }

        int length = 0; //当前走过的路径长度
        int temp = target; //目前所在位置（反推回到原点）
        int cross = 1; //每一个点所经历的分叉之积（其倒数为到达该点的概率）
        while(tree[temp] != -1) // 一步一步倒推回原点
        {
            temp = tree[temp];
            length++;
            if(temp != 1)
                cross = cross * (G[temp].size() - 1);
            else    cross = cross * G[temp].size(); //根结点要特殊考虑
        } 

        if(length > t) //如果t时间内到达不了target，则概率为0
            return 0; 

        //如果不用t时间就能到达target且target之后还有路可以走，则概率为0
        if (length < t && G[target].size() > 1)     
            return 0; 
        
        //如果target就是原点且原点之后还有路可以走，则概率为0（特殊考虑这种情况是因为原点没有祖先）
        if (t > 0 && target == 1 && n>1)) return 0;

        // 返回分叉之积的倒数，也就是跳到该点的概率
        return 1/(double)cross;        
    }
};

```
## 最后
欢迎大家给我提出各种意见哦，我也想优化一下我的本方法呢