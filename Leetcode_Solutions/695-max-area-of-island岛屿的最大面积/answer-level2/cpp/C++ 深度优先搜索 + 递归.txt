### 解题思路
[借鉴](https://leetcode-cn.com/problems/max-area-of-island/solution/dao-yu-de-zui-da-mian-ji-jian-dan-de-di-gui-tu-jie/)

### 代码

```cpp
class Solution {
public:
    int getArea( vector<vector<int>>& grid, int i, int j, int rows, int cols ) {
        if ( i > -1 && i < rows && j > -1 && j < cols && ( 1 == grid[i][j] ) ) {
            grid[i][j] = 0;
            return 1 + getArea( grid, i-1, j, rows, cols ) + getArea( grid, i+1, j, rows, cols ) + getArea( grid, i, j-1 , rows, cols ) + getArea( grid, i, j+1 , rows, cols );
        }

        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size(), cols = grid[0].size();
        for ( int i = 0; i < rows; ++i ) {
            for ( int j = 0; j < cols; ++j ) {
                if ( 1 == grid[i][j] ) {
                    // 以此为中心，向四周扩散
                    maxArea = max( maxArea, getArea( grid, i, j, rows, cols ) );
                }
            }
        }

        return maxArea;
    }
};
```