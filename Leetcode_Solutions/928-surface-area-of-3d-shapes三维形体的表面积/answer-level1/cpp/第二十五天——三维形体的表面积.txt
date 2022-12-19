### 解题思路
常规思路，逐点遍历，计算表面积值

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int area = 0, row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    area += 2;
                    for(auto di:dir){
                        int x = i + di.first;
                        int y = j + di.second;
                        if(x>=0 && x<row && y>=0 && y<col){
                            if(grid[x][y] < grid[i][j]) area += (grid[i][j] - grid[x][y]);
                        }
                        else area += grid[i][j];    
                        //int value = (x>=0 && x<row && y>=0 && y<col)?grid[x][y]:0;
                        //area += (value < grid[i][j])?(grid[i][j] - value):0;
                        //if(value < grid[i][j]) area += (grid[i][j] - value);
                    }
                }
            }
        }
        return area;
    }
};
```