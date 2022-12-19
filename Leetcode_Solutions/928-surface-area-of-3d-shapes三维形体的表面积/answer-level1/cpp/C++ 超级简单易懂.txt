1. 同一个点上堆叠的立方体n个，那么表面积 = n * 4 + 2；
2. 相邻的两个坐标上分别有2个,3个立方体，那么表面积减少min(2, 3) * 2； 

这两点明白了，代码很简单：
```c++
class Solution {
private:
    vector<vector<int>> dirs = {{0, -1}, {-1, 0}};  // 前、上两个方向

public:
    int surfaceArea(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                ans += grid[i][j] * 4 + 2;          // 堆叠的立方体表面积 = 个数 * 4 + 2

                for (auto& dir : dirs) {            // 只需要与前一个、上一个两个方向检查有没有交集
                    int nx = i + dir[0];
                    int ny = j + dir[1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] > 0) {
                        ans -= min(grid[nx][ny], grid[i][j]) * 2;   // 取个数少的，相邻坐标有一个就会少2个面
                    }
                }
            }
        }

        return ans;
    }
};
```


