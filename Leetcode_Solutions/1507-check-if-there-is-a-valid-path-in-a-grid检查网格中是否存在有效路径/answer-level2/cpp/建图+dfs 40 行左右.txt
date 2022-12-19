把每个格子转化成3*3的格子，有道路的地方写上1，之后dfs即可

```
class Solution {
    int map[1000][1000];
    void fill(int i, int j, int s)
    {
        map[i+1][j+1]=1;
        if(s==1) map[i+1][j]=map[i+1][j+2]=1;
        if(s==2) map[i][j+1]=map[i+2][j+1]=1;
        if(s==3) map[i+1][j]=map[i+2][j+1]=1;
        if(s==4) map[i+1][j+2]=map[i+2][j+1]=1;
        if(s==5) map[i+1][j]=map[i][j+1]=1;
        if(s==6) map[i+1][j+2]=map[i][j+1]=1;
    }
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    void dfs(int x, int y)
    {
        map[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(map[xx][yy]==0)continue;
            dfs(xx, yy);
        }
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(map,0,sizeof map);
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1;i<=3*n;i+=3)
            for(int j=1;j<=3*m;j+=3)
                fill(i,j,grid[i/3][j/3]);
        dfs(2,2);
        return map[3*n-1][3*m-1]==0;
    }
};
```
顺便推荐一道很类似的题，Maze Connect，http://serjudging.vanb.org/wp-content/uploads/Maze-Connect.pdf
不过这样写可能不是最快的，我花了15分钟。。几乎是剩下三道题时间之和。。

后来想到map部分的函数也可以压缩，这样写比赛的时候可能会更省时间，代码也更短：
```
class Solution {
    int map[1000][1000];
    int o[6][4]={1,0,1,2,0,1,2,1,1,0,2,1,1,2,2,1,1,0,0,1,1,2,0,1};
    void fill(int i, int j, int s)
    {
        map[i+1][j+1]= map[i+o[s][0]][j+o[s][1]] = map[i+o[s][2]][j+o[s][3]]=1;
    }
    int dir[4][2] = {0,1,1,0,-1,0,0,-1};
    void dfs(int x, int y)
    {
        map[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(map[xx][yy]==0)continue;
            dfs(xx, yy);
        }
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(map,0,sizeof map);
        int n = grid.size();
        int m = grid[0].size();
        for(int i=1;i<=3*n;i+=3)
            for(int j=1;j<=3*m;j+=3)
                fill(i,j,grid[i/3][j/3]-1);
        dfs(2,2);
        return map[3*n-1][3*m-1]==0;
    }
};
```
