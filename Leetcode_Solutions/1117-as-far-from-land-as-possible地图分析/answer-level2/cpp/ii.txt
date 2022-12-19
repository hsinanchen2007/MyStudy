### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0) return -1;
        int m=grid[0].size();
        vector<vector<int> > dl(grid.size(),vector<int>(grid[0].size(),999));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) dl[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) dl[i][j]=0;
                else {
                    if(i-1>=0) dl[i][j]=min(dl[i][j],dl[i-1][j]+1);
                    if(j-1>=0) dl[i][j]=min(dl[i][j],dl[i][j-1]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==1) continue;
                if(i+1<n) dl[i][j]=min(dl[i][j],dl[i+1][j]+1);
                if(j+1<m) dl[i][j]=min(dl[i][j],dl[i][j+1]+1);
            }
        }
        int resmax=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(resmax<dl[i][j] && grid[i][j]==0) resmax=dl[i][j];
            }
        }
        return resmax>=999?-1:resmax;
    }
};







```