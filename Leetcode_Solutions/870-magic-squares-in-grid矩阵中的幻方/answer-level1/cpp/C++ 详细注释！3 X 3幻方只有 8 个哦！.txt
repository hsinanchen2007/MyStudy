### 解题思路
见注释即可。

### 代码

```cpp
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // 1. 3 X 3 幻方只有 8 个
        const unordered_set<int> magic_33 { 816357492, 834159672, 618753294, 672159834,
                                   492357816, 438951276, 294753618, 276951438 };
        
        // 2. 3 X 3 矩阵偏移数组，以右下角为基准 (0, 0)，其他元素相对偏移量
        const int offset[][2] = { {-2, -2}, {-2, -1}, {-2, 0},
                                  {-1, -2}, {-1, -1}, {-1, 0},
                                  { 0, -2}, { 0, -1}, { 0, 0},};
        
        int result = 0;
        int tmp_sum = 0;

        // 3. i = 2, j = 2 表示从第一个 3 X 3 矩阵开始计算
        for (int i = 2; i < grid.size(); i++) {
            for (int j = 2; j < grid[0].size(); j++) {
                tmp_sum = 0;
                for (int k = 0; k < 9; k++) {
                    // 4. 计算每个 3 X 3 矩阵的和，当 i = 2, j = 2, k = 0 时：
                    // grid[2 + offset[0][0]] = grid[2 - 2] = grid[0]
                    // grid[2 + offset[0][1]] = grid[2 - 2] = grid[0]
                    // 表示累加第一个元素到 tmp_sum * 10 中，tmp_sum 每次加一位
                    tmp_sum = tmp_sum * 10 + grid[i + offset[k][0]][j + offset[k][1]];
                }

                // 5. 如果计算的和在 3 X 3 幻方集合中，count(tmp_sum) = 1，计数器加 1 
                result += magic_33.count(tmp_sum);
            }
        }

        return result;
    }
};
```