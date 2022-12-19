```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int slong = 0;
        for(int i = 0 ; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1){
                    int nei = 0;
                    if(i > 0 && grid[i-1][j] == 1) nei++;
                    if(i != grid.size() - 1 && grid[i+1][j] == 1)  nei++;
                    if(j > 0 && grid[i][j-1] == 1) nei++;
                    if(j != grid[i].size() - 1 && grid[i][j+1] == 1) nei++;
                    slong += 4 - nei;
                }    
            }
        }
        return slong;
    }
};
```
![image.png](https://pic.leetcode-cn.com/77aa62473a35f22379d3f60447a6b2f05bacea561ca0963c7f56846160001a43-image.png)
