### 解题思路
采用广度优先遍历。
对地图中的每个点都广度优先遍历一下，找到距离此点最短的陆地的距离。对所有点都遍历完后，取此距离的最大值，这个最大值对应的海洋就是离陆地最远的海洋。

### 代码

1.单源的BFS
```cpp
class Solution {
public:
    static constexpr int dx[4]={0,-1,0,1};
    static constexpr int dy[4]={-1,0,1,0};//方向向量
    int n;//地图的大小
    static constexpr int N=100;
    bool visited [N][N];//记录每个点是否访问过，对新的点进行广度优先遍历之前，要将这个数组中的所有值设置为false
    struct cooridate{int x;int y;int disto;};//记录加入队列的点信息disto表示离原点的距离
    int maxDistance(vector<vector<int>>& grid){
        n=grid.size();
        int ans=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,findNearestLand(i,j,grid));
            }
        }

        return ans;
    }
    //找到距离点(x,y)最近的陆地与(x,y)的距离
    int findNearestLand(int x,int y,vector<vector<int>>& grid){
        if(grid[x][y]) return -1;//如果要遍历的点是陆地，则直接返回-1

        memset(visited,0,sizeof(visited));//每次遍历前，将标记是否访问过的数组都清空
        //将遍历的原点放进队列中，并标记visited
        queue<cooridate> q;
        q.push({x,y,0});
        visited[x][y]=1;
        
        while(!q.empty()){
            cooridate temp=q.front();//记录队列最前面被推出来的点
            q.pop();
            //查看被推出点的四个方向的点，注意被推出点的坐标为(tmep.x,temp.y)
            for(int i=0;i<4;i++){
                //被推出点的四个零点
                int nx=temp.x+dx[i];
                int ny=temp.y+dy[i];
                //判断周围的点是否在地图范围内
                if(nx<n&&nx>=0&&ny<n&&ny>=0){
                    //若此点未被访问过，加入队列，若加入的是陆地，则直接范围该陆地距离原点的距离
                    if(!visited[nx][ny]){
                        q.push({nx,ny,temp.disto+1});
                        visited[nx][ny]=1;
                        if(grid[nx][ny]) return temp.disto+1;
                    }
                }
            }
        }
        //队列为空了，仍然没有返回一个陆地到原点的距离，那么就说明此地图全是海洋
        return -1;
    }
};
```

2.多源的BFS，将所有的陆地作为一个超级源点，开始BFS
```cpp

class Solution {
public:
    static constexpr int dx[4]={0,-1,0,1};
    static constexpr int dy[4]={-1,0,1,0};

    static constexpr int INF=10e6;//在BFS之前所有的海洋到陆地的距离均定义为INF
    
    int n;
    struct cooridate{int x;int y;};

    int maxDistance(vector<vector<int>>& grid){
        n=grid.size();

        int dis[n][n];//记录地图中每个点到自己最近陆地的距离

        int ans=-1;
        queue<cooridate> q;

        //对数组dis初始化

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                //如果对应的点是陆地，则把距离设为0，并将该点推入队列中
                if(grid[i][j]) {
                    dis[i][j]=0;
                    q.push({i,j});
                }
                //如果点是海洋，则设定距离为INF
                else dis[i][j]=INF;
            }   
        
        while(!q.empty()){
            cooridate temp=q.front(); 
            q.pop();
            for(int k=0;k<4;k++){
                int nx=temp.x+dx[k];
                int ny=temp.y+dy[k];

                if(nx<n&&nx>=0&&ny<n&&ny>=0){
                    //松弛操作
                    if(dis[nx][ny]>dis[temp.x][temp.y]+1)
                    {
                        dis[nx][ny]=dis[temp.x][temp.y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                ans=max(ans,dis[i][j]);
            }
        
        if(ans==0) ans=INF;
        return ans==INF?-1:ans;
    }
};
```

3.动态规划
```cpp
class Solution {
public:
    
    static constexpr int INF=10e6;
    int n;
    int maxDistance(vector<vector<int>>& grid){
        n=grid.size();
        int dis[n][n];
        int ans=-1;
        //设置每个点到最近陆地的距离，如果是海洋则初始化为INF，如果为陆地则设置为0
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                dis[i][j]=grid[i][j]?0:INF;
            }   
        
        //动态规划，某个点是从上面或者左面的点而来，或者从下面或者右面而来
        //那么此点距最近陆地的距离就是上面、左面加一；亦或者下面、右面加一

        **/*关键：到某个点的最短距离总是从四个方向而来*/**

        //从上遍历地图，更新每个节点到最近陆地的距离
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(i-1>=0)
                    dis[i][j]=min(dis[i-1][j]+1,dis[i][j]);
                if(j-1>=0)
                    dis[i][j]=min(dis[i][j-1]+1,dis[i][j]);
            }
        //从下遍历地图
        for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                if(i+1<n)
                    dis[i][j]=min(dis[i+1][j]+1,dis[i][j]);
                if(j+1<n)
                    dis[i][j]=min(dis[i][j+1]+1,dis[i][j]);
            }
        
         for(int i=n-1;i>=0;i--)
            for(int j=n-1;j>=0;j--){
                ans=max(ans,dis[i][j]);
            }

        if(ans==0) ans=INF;
        return ans==INF?-1:ans;
    }
};
```


