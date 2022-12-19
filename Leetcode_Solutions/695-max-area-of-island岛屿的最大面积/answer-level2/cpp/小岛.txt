### 解题思路


### 代码

```cpp
// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int resmax=0;
//         int n=grid.size(),m=grid[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1) {resmax=max(dfs(grid,i,j,0),resmax);grid[i][j]=0;}
//             }
//         }
//         return resmax;
//     }
//     int dfs(vector<vector<int> >& grid,int nowi,int nowj,int ans){
//         ans++;
//         if(nowi+1<grid.size() && grid[nowi+1][nowj]==1) {ans+=dfs(grid,nowi+1,nowj,0);grid[nowi+1][nowj]=0;}
//         if(nowi-1>=0 && grid[nowi-1][nowj]==1) {ans+=dfs(grid,nowi-1,nowj,0);grid[nowi-1][nowj]=0;}
//         if(nowj+1<grid[0].size() && grid[nowi][nowj+1]==1) {ans+=dfs(grid,nowi,nowj+1,0);grid[nowi][nowj+1]=0;}
//         if(nowj-1>=0 && grid[nowi][nowj-1]==1) {ans+=dfs(grid,nowi,nowj-1,0);grid[nowi][nowj-1]=0;}
//         return ans;
//     }
// };
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int resmax=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) resmax=max(dfs(grid,i,j,0),resmax);
            }
        }
        return resmax;
    }
    int dfs(vector<vector<int> >& grid,int nowi,int nowj,int ans){
        ans++;
        grid[nowi][nowj]=0;
        if(nowi+1<grid.size() && grid[nowi+1][nowj]==1) ans+=dfs(grid,nowi+1,nowj,0);
        if(nowi-1>=0 && grid[nowi-1][nowj]==1) ans+=dfs(grid,nowi-1,nowj,0);
        if(nowj+1<grid[0].size() && grid[nowi][nowj+1]==1) ans+=dfs(grid,nowi,nowj+1,0);
        if(nowj-1>=0 && grid[nowi][nowj-1]==1) ans+=dfs(grid,nowi,nowj-1,0);
        return ans;
    }
};
```