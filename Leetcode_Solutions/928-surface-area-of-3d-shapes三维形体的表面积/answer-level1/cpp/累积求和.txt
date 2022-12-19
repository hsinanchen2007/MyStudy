### 解题思路
首先要看懂题，下表面的表面积也是要计算的。
1.如果该格上有数据，那么首先直接累加每个格的表面积： 2+4×V
2.然后查看格的4周，如果也有数据，那么就减掉较低部分被遮挡的表面积：min（v，v'）

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int dim = grid.size();
        int area = 0;
        for(int i=0; i<dim; i++) {
            for (int j=0; j<dim; j++) {
                int new_area = grid[i][j] > 0 ? 2+4*grid[i][j] : 0;
                area +=new_area;
                if(i-1>=0) {
                    area -= min(grid[i][j], grid[i-1][j]);
                }
                if (i+1<dim) {
                    area -= min(grid[i][j], grid[i+1][j]);
                }
                if (j-1 >= 0) {
                    area -= min(grid[i][j], grid[i][j-1]);
                }
                if (j+1 < dim) {
                    area -= min(grid[i][j], grid[i][j+1]);
                }
            }
        }
        return area;
    }
};
```