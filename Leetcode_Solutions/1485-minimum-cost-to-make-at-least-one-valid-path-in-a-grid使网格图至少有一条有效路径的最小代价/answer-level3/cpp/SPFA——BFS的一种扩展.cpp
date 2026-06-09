一句话总结本篇题解内容：**BFS中每个点只入列一次，但有时，我们可能需要bfs中允许一个点入列多次才能解决问题，这种方法就是SPFA。**

SPFA这种算法，如果你百度的话，你会发现大多是说他用于求最短路的，事实上，更宽泛的来理解，所有“可能要后悔”的BFS，都可以用类似SPFA的思路来解决。

先说说经典的最短路问题，希望大家能借此理解为何说SPFA是可以“后悔”的。

![图.jpg](https://pic.leetcode-cn.com/52dea11543c692564dded7fe71409d6749cc4d95668a9a3bb4658ae23b381176-%E5%9B%BE.jpg)

考虑这样一张图，1号点是起点，边上的数字代表这条边的长度，你想求出1到10号点的最短路。

下面，说说为何朴素的bfs不行。

按照bfs的流程，初始1号点入列，然后1号点周围的2号和3号入列。此时，2距1最短路更新为4,3距1最短路更新为1。

于是，问题来了，我们看到，实际上1到2的最短路是1->3->4->2，其长度为2。

但按照朴素的BFS来做，由于已经有vis[2]=1了，所以由4号点访问周围点时，2号点就不会再入列了，这样，我们就会求出错误的最短路。

那怎么办呢？一个很显然的办法，就是————————那我就再把2入列呗！

所以，SPFA其实就是很简单的一件事儿：检测到某点距离变化，就把某点入列。

并且如前所述，这样的SPFA其实就不需要vis数组了，因为只要距离更新，点就要入列。

但下面代码中还是有vis数组，其实他的含义是：某个点当前正在队列里，vis值为1，当前点不在队列里，vis值为0。
需要注意，虽然名字都叫vis，但这里的vis数组和朴素BFS中的vis数组很不一样。
这里vis数组只是避免同一个点**已经在队列里**的情况下被加入队列多次而用的（再次强调，SPFA是允许一个点多次入列的，只不过正在队列里的，确实没必要再入列了）。


那么具体看这道题，dis[i][j]表示到达第i行第j列的点所需要的最小花费，直接的状态转移看上去并不好想。

怎么办？

不好想就不想了呗！

只要某个点dis变得更小了，我们按照SPFA的思想，就二话不说给他入列，让他再更新周围点的dis，这样总是对的了吧。

所以说白了，SPFA，听上去高大上，其实是贼暴力的一种方法，只要检测到某点dis值改变，就在重新由这点开始bfs，仅此而已。


下面是代码：
```
class Solution {
public:
    bool ok(int x,int y,int m,int n){
        if(x<0||x>=m||y<0||y>=n)
            return false;
        return true;
    }
    int minCost(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int dis[110][110];      //dis[i][j]:到达i行j列点的最小花费
        int vis[110][110]={0};  //vis[i][j]:i行j列点是否正在队列中
        queue<pair<int,int> > q;
        memset(dis,0x3f,sizeof(dis));
        q.push({0,0});
        vis[0][0]=1;dis[0][0]=0;
        int dx[]={0,0,0,1,-1},dy[]={0,1,-1,0,0};    
        //以上是初始化
        while(!q.empty()){
            int xx=q.front().first;
            int yy=q.front().second;
            vis[xx][yy]=0;q.pop();
            for(int i=1;i<=4;i++){
                int xto=xx+dx[i];
                int yto=yy+dy[i];
                if(ok(xto,yto,m,n)){
                    int tmp=0;
                    if(g[xx][yy]==i){   
                        //这里用了个取巧的写法，就是把dx和dy四个方向和输入格式的四个方向一一对应，便于写代码
                        tmp=dis[xx][yy];
                    }
                    else{
                        tmp=dis[xx][yy]+1;
                    }
                    if(tmp<dis[xto][yto]){
                        dis[xto][yto]=tmp;
                        if(!vis[xto][yto]){
                            q.push({xto,yto});
                            vis[xto][yto]=1;
                        }
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};
```
