### 解题思路
同时向右和向下扫描：
1、统计立方体个数total
2、统计左右相邻两个立方体重叠的面数 min(grid[i][j], grid[i+1][j])
3、统计上下相邻两个立方体重叠的面数 min(grid[i][j], grid[i][j+1])
4、统计立方体层叠重叠的面数 max(0, grid[i][j] - 1)

### 代码

```cpp
class Solution {
public:
int surfaceArea(vector<vector<int>>& grid) {
    int total = 0;
    int inner = 0;
    for(int row = 0; row < grid.size(); row++){
        for(int col = 0; col < grid[0].size(); col++){
            if(col + 1 < grid[0].size()){
                inner += min(grid[row][col], grid[row][col +1]);
            } 
            
            if(row + 1 < grid.size()){
                inner += min(grid[row][col], grid[row + 1][col]);
            }
            
            total += grid[row][col];
            inner += grid[row][col] > 0 ? grid[row][col] - 1 : 0;
        }
    }
    
    return total * 6 - inner * 2;
}
};
```