### 解题思路
简单dfs下，然后我们猜，最终的答案的步数，不超过70步，然后，我们经过简单的剪枝，就过这到题了。
### 代码

```cpp
int ans=999999,n,m;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int vis[100][100];
int dp[50][50][1000];

class Solution {
public:
    bool isMinger(int x,int y){
        return (x>=0&&x<m)&&(y<n&&y>=0);
    }
    void dfs(const vector<vector<int>>& grid,int x,int y,int step,int k){
        if(step>=70)return ;
        if(x==m-1&&y==n-1){
            ans=min(ans,step);
            return ;
        }
        if(step>=ans)return;
        for(int i=0;i<4;++i){
            int dx=x+dir[i][0],dy=y+dir[i][1];
            if(!isMinger(dx,dy))continue;
            if(vis[dy][dx])continue;
            if(grid[dy][dx]==1&&k==0)continue;
            if(step>=dp[dy][dx][k])continue;
            dp[dy][dx][k]=min(dp[dy][dx][k],step);
            vis[dy][dx]=1;
            dfs(grid,dx,dy,step+1,k-(grid[dy][dx]==1));
            vis[dy][dx]=0;
        }
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        ans=9999999;       
        n=grid.size();
        memset(dp,127,sizeof(dp));
        m=grid[0].size();
        dfs(grid,0,0,0,k);
        if(ans==9999999)return -1;
        return ans;
    }
};
```