统计岛屿的方格数count_island和；
统计岛屿小方格东南俩面（或西北）相邻的方格数count，即如果一个小方格grid[i][j]是1，如果grid[i][j+1]=1,则count+1，如果grid[i+1][j]=1，count+1
岛屿的周长为 4*count_island-2*count;

```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count_island=0;
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    count_island++;
                    if(j+1<grid[i].size()&&grid[i][j+1]==1)
                        count++;
                    if(i+1<grid.size()&&grid[i+1][j]==1)
                        count++;
                }
            }
        return count_island*4-count*2;
    }
};
```
