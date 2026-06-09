## 暴力bfs
这种思路最简单明了，那就是从t=0开始，bfs遍历整个图，判断当前水位是否满足条件，如果满足条件直接返回即可。
```cpp
class Solution {
public:
    static const int maxn = 100;
    int rain[maxn][maxn];
    bool vis[maxn][maxn];
    struct node{
        int x,y;
        node(int a=0,int b=0):x(a),y(b){}
    };
    int n;

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    bool bfs(vector<vector<int>>& grid,int depth){
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        queue<node> que;
        que.push(node(0,0));
        node p;
        int x,y;
        while(!que.empty()){
            p=que.front();
            que.pop();
            if(p.x==n-1&&p.y==n-1)  return true;
            for(int i=0;i<4;i++){
                x=p.x+dx[i];
                y=p.y+dy[i];
                if(x<n&&x>=0&&y<n&&y>=0){
                    if(!vis[x][y]&&depth>=grid[x][y]){
                        vis[x][y]=1;
                        que.push(node(x,y));
                    }
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int mx=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mx<grid[i][j])   mx=grid[i][j];
            }
        }
        for(int i=grid[0][0];i<=mx;i++){
            if(bfs(grid,i))  return i;
        }
        return mx;
    }
};
```
跳台的最大值是n^2，每次bfs最坏是n^2，那么整体时间复杂度O(n^4)。

## 优先级队列
当然如果从贪心的角度来看的话，从0，0出发，每次都选择周围最小的前进。但是这种贪心的解不一定是最优的，比如我一开始不断向右，到达最右端的时候如果此时的下方非常大，还不如一开始就选择向下走。也就是说在此时的邻接最小有了更新。那么很自然的就想到了小根堆。从左上角开始扩散邻接点，并且记录途中的最大值即可。
```cpp
class Solution {
public:
    static const int maxn = 100;
    bool vis[maxn][maxn];
    struct node{
        int x,y;
        int h;
        node(int a=0,int b=0,int c=0):x(a),y(b),h(c){}
        bool operator < (const node b)const{
            return h>b.h;
        }
    };
    int n;

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    int bfs(vector<vector<int>>& grid){
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        priority_queue<node> que;
        que.push(node(0,0,grid[0][0]));
        node p;
        int x,y;
        int mx=-1;
        while(!que.empty()){
            p=que.top();
            que.pop();
            if(mx<p.h)  mx=p.h;
            if(p.x==n-1&&p.y==n-1)  return mx;
            for(int i=0;i<4;i++){
                x=p.x+dx[i];
                y=p.y+dy[i];
                if(x<n&&x>=0&&y<n&&y>=0){
                    if(!vis[x][y]){
                        vis[x][y]=1;
                        que.push(node(x,y,grid[x][y]));
                    }
                }
            }
        }
        return mx;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int mx=bfs(grid);
        return mx;
    }
};
```
以此bfs的时间复杂度是n^2。从优先级队列中取出最小值的上界是logn，但是该上界严格不紧。所以总时间复杂度是O(n^2logn)。