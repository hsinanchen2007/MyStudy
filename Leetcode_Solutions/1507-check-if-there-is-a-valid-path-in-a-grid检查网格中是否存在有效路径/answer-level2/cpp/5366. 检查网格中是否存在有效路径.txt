#### 解题思路
在比赛结束的最后，我做好了。简直就是残忍
写的有点乱。
大概的意思呢。就是对于每一块网格，他有着两个可以走的方向。
用dir数组，表示四个方向。用a数组存放每一种街道类型可以走的两个方向。
例如针对示例1.对于grid[0][0]而言，他的值为2，在a中找到对应下标为2的值。也就是{0，1}
表示在[0][0]有两个方向可以走，一个是0，一个是1。
对应到dir数组，0是{-1，0}，也就是下一个位置可以是(x-1,y+0)，也就是向下走
1是{1,0},也就是下一步的位置是(x+1,y+0),也就是向上走。
因此我们可以，根据grid的输入，得到每一个网格可以走的下一步的位置。
还要再判读下一步的网格和当前网格是否连通。如果连通的话，要么是左右连通，要么是上下连通，都可以得到以下的式子。
dir[t][0] + dir[p][0]==0 && dir[t][1]+dir[p][1]==0
以上是构建图的过程。可以知道下一步可以走的位置，以及下一步是否可以走
接下来，可以利用dfs来进行求解。最后只需要判读(m-1,n-1)位置是否被访问过即可。
```
class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//定义四个方向，上下左右
    //建立形状和方向的映射
    int a[7][2] = {{0,0},{2,3},{0,1},{1,2},{1,3},{0,2},{0,3}};
    int n,m;
    bool visited[500][500];
    //判读顶点是否规范
    bool check(int x,int y){
        if(x < 0 || x >= m || y<0 || y >= n){
            return false;
        }
        return true;
    }
    void dfs(int x,int y,vector<vector<int>>& grid){
        if(check(x,y)==false) return;
        visited[x][y] = true;//标记访问
        // cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
        int tmpdir = grid[x][y];//取出该点的街道类型
        for(int i=0;i<2;i++){
            int t = a[tmpdir][i];
            int tx = dir[t][0] + x;
            int ty = dir[t][1] + y;         
            //(tx,ty)是下一跳可到达的点。需要再去判读，该点是否和
            if(check(tx,ty)){
                // cout<<"tx="<<tx<<"\t"<<"ty="<<ty<<endl;
                int tmp = grid[tx][ty];//得到下一步的街道类型
                for(int k=0;k<2;k++){
                    int p = a[tmp][k];//得到该街道的两个方向
                    if(dir[t][0] + dir[p][0]==0 && dir[t][1]+dir[p][1]==0){//判读是否可以走通
                        if(!visited[tx][ty]){
                            dfs(tx,ty,grid);
                        }                    
                    }
                }                
            }
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();//行数
        n = grid[0].size();//列数
        dfs(0,0,grid);
        if(visited[m-1][n-1] == true){
            return true;//可到达
        }
        return false;
    }
};
```
