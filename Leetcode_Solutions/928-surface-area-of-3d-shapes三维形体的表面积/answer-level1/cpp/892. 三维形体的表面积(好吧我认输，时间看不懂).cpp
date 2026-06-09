### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size = grid.size();
        int area = 0;
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size; ++j)
            {
                if(grid[i][j])  // 如果方块数量不为0
                {
                    area += grid[i][j] * 4 + 2;
                    if(j != size-1) // 如果不为最上的方块
                        area -= min(grid[i][j], grid[i][j+1]) * 2;
                    if(i != size-1) // 如果不是最右的方块
                        area -= min(grid[i][j], grid[i+1][j]) * 2;
                }
                    
            }
        return area;
    }
};
```