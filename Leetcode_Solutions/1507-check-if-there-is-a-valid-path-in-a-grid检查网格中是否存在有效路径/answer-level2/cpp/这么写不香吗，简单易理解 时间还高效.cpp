不就是一个变种dfs吗，就是迷宫加强版，限制了每个点能走的方向以及下一步能走的位置
```
class Solution {
public:
    int n,m;
    int go[7][2][2] = {
        { {0,0},{0,0}  },
        { {0,1},{0,-1} },//1
        { {-1,0},{1,0} },//2
        { {0,-1},{1,0} },//3
        { {1,0},{0,1} },//4
        { {-1,0},{0,-1} },//5
        { {-1,0},{0,1} }//6
    };
    int cantgo[7][2][3] = {
        { {0,0,0},{0,0,0}  },
        { {2,4,6},{2,3,5} },//1
        { {1,5,6},{1,3,4} },//2
        { {2,3,5},{1,3,4} },//3
        { {1,3,4},{2,4,6} },//4
        { {1,5,6},{2,3,5} },//5
        { {1,5,6},{2,4,6} }//6
    };
    int vis[500][500]={0};
    int g_able=false;
    bool dfs(vector<vector<int>>& grid, int x,int y){
        vis[x][y]=1;
        if(g_able || (x == n-1 && y == m-1)){
            g_able=true;
            return true; 
        }  
        for(int i=0;i<2;++i){
            int nx = x+go[grid[x][y]][i][0];
            int ny = y+go[grid[x][y]][i][1];
            if(nx>= n||nx<0||ny>=m||ny<0||vis[nx][ny]) continue;
            int tmp=grid[nx][ny];
            if(tmp==cantgo[grid[x][y]][i][0] || tmp==cantgo[grid[x][y]][i][1] || tmp==cantgo[grid[x][y]][i][2]) continue;
            vis[nx][ny]=1;
            dfs(grid,nx,ny);
            vis[nx][ny]=0;

        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(vis,0,sizeof(vis));
        g_able=false;
        n=grid.size();m=grid[0].size();
        dfs(grid,0,0);
        if(g_able)return true;
        return false;
    }
};
```
