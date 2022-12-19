**简单dfs即可通过**
**注意封闭岛屿是不存在与边界联通的情况**
```
class Solution {
public:
    int flag=true;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    void dfs(vector<vector<int>>& grid,int x,int y){
        if(grid[x][y]==-1||grid[x][y]==1)return;记忆化搜索
        grid[x][y]=-1;
        if(x==grid.size()-1||x==0||y==0||y==grid[0].size()-1)flag=false;//筛选掉与边界联通的情况
        for(int i=0;i<4;i++){
            int a=x+dx[i],b=y+dy[i];
            if((a>=0&&a<grid.size()&&b>=0&&b<grid[0].size())&&grid[a][b]==0)
                dfs(grid,a,b);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        //判断简单图的独立连通分量个数
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                {
                    flag=true;
                    dfs(grid,i,j);
                    if(flag)ans++;
                }
            }
        }
        return ans;
    }
};
```
