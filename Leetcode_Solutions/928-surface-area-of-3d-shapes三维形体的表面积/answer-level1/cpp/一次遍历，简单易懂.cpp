### 解题思路

1.每个正方形六个面。
2.上下重叠一次少俩面露在外头。
3.左右重叠则少一个面露在外头（因为每个柱体都要算一遍）。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=0;
        int decrease=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                n+=grid[i][j];
                if(grid[i][j]>1) decrease+=(grid[i][j]-1)*2;
                if(i-1>=0) decrease+=min(grid[i][j],grid[i-1][j]);
                if(i+1<grid.size()) decrease+=min(grid[i][j],grid[i+1][j]);
                if(j-1>=0) decrease+=min(grid[i][j],grid[i][j-1]);
                if(j+1<grid[0].size()) decrease+=min(grid[i][j],grid[i][j+1]);
            }
        }
        int facet=n*6-decrease;
        return facet;
    }
};
```