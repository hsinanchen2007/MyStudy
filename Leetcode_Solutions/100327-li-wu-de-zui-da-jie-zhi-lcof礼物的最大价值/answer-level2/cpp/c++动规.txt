### 解题思路
状态转移方程
grid[i][j]=max(grid[i][j-1],grid[i-1][j])+grid[i][j];
### 代码

```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                grid[i][j]=max(j>0?grid[i][j-1]:0,i>0?grid[i-1][j]:0)+grid[i][j];
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
```