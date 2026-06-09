C++ beats 90%. 朴素直观的解法， 对每个为1的单元，检查它的上下左右是否为0或者为边界

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    if(i==0 || grid[i-1][j]==0) res++;
                    if(i == grid.size()-1 || grid[i+1][j]==0) res++;
                    if(j==0 || grid[i][j-1]==0) res++;
                    if(j==grid[i].size()-1 || grid[i][j+1]==0) res++;
                }
            }
        }
        return res;
    }
};
```
