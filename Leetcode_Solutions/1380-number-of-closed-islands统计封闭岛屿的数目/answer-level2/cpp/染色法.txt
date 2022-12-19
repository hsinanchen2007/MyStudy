### 解题思路
从四条边界入手可以染色所有非岛的陆地；之后通过染色遍历小岛数量

### 代码

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int i=0,j=0;
        int width=grid[0].size();
        int height=grid.size();
        //边界染色
        for(j=0;j<width;++j)
          {if(grid[0][j]==0) virus(grid,0,j,-2);}
        for(j=0;j<width;++j)
          {if(grid[height-1][j]==0) virus(grid,height-1,j,-2);}
        for(i=1;i<height-1;++i)
          {if(grid[i][0]==0) virus(grid,i,0,-2);}
        for(i=1;i<height-1;++i)
          {if(grid[i][width-1]==0) virus(grid,i,width-1,-2);}
        //小岛遍历
        int ans=0;
        for(i=1;i<height-1;++i){
            for(j=1;j<width-1;++j){
                if(grid[i][j]==0){
                    ans++;
                    virus(grid,i,j,-1);
                }}}
      return ans;
    }
void virus(vector<vector<int>>& grid,int i,int j,int color){
    grid[i][j]=color;
    if(i!=0&&grid[i-1][j]==0) virus(grid,i-1,j,color);
    if(i!=grid.size()-1&&grid[i+1][j]==0) virus(grid,i+1,j,color);
    if(j!=grid[0].size()-1&&grid[i][j+1]==0) virus(grid,i,j+1,color);
    if(j!=0&&grid[i][j-1]==0) virus(grid,i,j-1,color);   
}
};
```