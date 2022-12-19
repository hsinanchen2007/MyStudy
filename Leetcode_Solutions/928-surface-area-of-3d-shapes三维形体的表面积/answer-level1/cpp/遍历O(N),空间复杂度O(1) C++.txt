### 解题思路
总面积，减去折叠的面积。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }

        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        int redudant = 0;
        for(int i = 0 ; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cnt += grid[i][j];
                redudant +=coverFaceNum(grid, grid[i][j], i, j-1);
                redudant +=coverFaceNum(grid, grid[i][j], i, j+1);
                redudant +=coverFaceNum(grid, grid[i][j], i-1, j);
                redudant +=coverFaceNum(grid, grid[i][j], i+1, j);
                redudant +=grid[i][j] > 1 ? (grid[i][j] - 1)*2 : 0; 
            }
        }
        return 6*cnt - redudant;
    }

    int coverFaceNum(vector<vector<int>>& grid, int v, int i, int j)
    {
        int row = grid.size();
        int col = grid[0].size();

        bool invalid = (i < 0 || i >= row || j < 0 || j >= col);
        if (invalid){
            return 0;
        }

        return min(v, grid[i][j]);
    }
};
```