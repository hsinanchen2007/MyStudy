普通的BFS边的权值都是1。
0-1BFS表示的是边的权值可能为0，可以为1.
```
class Solution {
public:
    //0-1BFS,需要使用deque：双端队列
    //可以将箭头方向的cost看成0，其他方向的cost看成1，一直计算下去。。。
    
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        deque<pair<int,int>>dq;//算是初始化，一开始点所在的位置。。。这是一个双端队列,第一个数据是一维的位置，第二个数据是cost
        dq.push_front(make_pair(0,0));
        //代价小的cost放在双端队列前面优先出队，代价大的放在优先队列后面，因为我们需要尽量选择代价小的路径
        vector<vector<int>>dir{{0,1},{0,-1},{1,0},{-1,0}};//依次表示的是从0：{0,1}右，1：{0,-1}左，2:{1,0}下，3:{-1,0}上
        vector<int>vis(m*n,0);//表示已经扩展过了。。。
        while(!dq.empty()){
            auto [p,cost]=dq.front();
            //pair<int,int>q=dq.front();
            //int p=q.first,cost=q.second;
            dq.pop_front();
            int px=p/n,py=p%n;
            if(px==m-1&&py==n-1)return cost;
            if(vis[p]++)continue;//如果已经扩展过了，那么就不用再扩展了。。。
            for(int i=0;i<4;i++){
                int tx=px+dir[i][0],ty=py+dir[i][1];
                int tp=tx*n+ty;
                if(tx<0||tx>=m||ty<0||ty>=n||vis[tp])continue;
                if(grid[px][py]==i+1){//表示的是不需要更改方向
                    dq.push_front(make_pair(tp,cost));
                }else{
                    dq.push_back({tp,cost+1});//表示的是需要更改方向这时加入队尾，因为有可能有比这个更好的选择。。。
                }
                
            }
        }
        return -1;
    }
};
```
