```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    ++res;
                    set(grid,i,j);
                }
            }
        }
        return res;   
    }
    void set(vector<vector<char>>& grid,int i,int j){
        grid[i][j]='2';
        if(j-1>=0&&grid[i][j-1]=='1')set(grid,i,j-1);
        if(j+1<grid[0].size()&&grid[i][j+1]=='1')set(grid,i,j+1);
        if(i-1>=0&&grid[i-1][j]=='1')set(grid,i-1,j);
        if(i+1<grid.size()&&grid[i+1][j]=='1')set(grid,i+1,j);
    }
};
```
