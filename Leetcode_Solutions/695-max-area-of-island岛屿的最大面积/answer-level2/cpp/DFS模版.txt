### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    bool visit[51][51]={false};
    bool judge(vector<vector<int>>& grid,int x,int y){
        int bx=grid.size();
        int by=grid[0].size();
        if(x<0||x>=bx||y<0||y>=by||grid[x][y]==0||visit[x][y]==true) return false;
        return true;
    }
    int dfs(vector<vector<int>>& grid,int x,int y){
        int num=1;
        visit[x][y]=true;
        for(int i=0;i<4;i++){
            int newx=X[i]+x;
            int newy=Y[i]+y;
            if(judge(grid,newx,newy))
            num+=dfs(grid,newx,newy);
        }
        return num;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int bx=grid.size();
        int by=grid[0].size();
        int ans=0, cnt=0,sum=0;
        for(int i=0;i<bx;i++){
            for(int j=0;j<by;j++){
                if(grid[i][j]==1&&!visit[i][j]){
                   sum=dfs(grid,i,j);
                   ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};
```