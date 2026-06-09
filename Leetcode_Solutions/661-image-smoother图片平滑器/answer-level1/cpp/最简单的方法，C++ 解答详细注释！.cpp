### 解题思路
每次遍历一个数值，计算其正确的九宫格上下左右界限，然后求和，取平均值并赋值给当前遍历的数值。

详细过程见注释。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        int col = M[0].size();

        vector<vector<int>> smooth(row, vector<int>(col, -1));

        // 1. 当前元素坐标
        int cur_row = 0;
        int cur_col = 0;

        // 2. 包围当前元素的 9 个数值的上下左右坐标
        int x_l = 0;
        int x_r = 0;
        int y_t = 0;
        int y_b = 0;

        // 3. 每个平滑九宫格的总和
        int sum = 0;

        // 4. 每次遍历一个数值
        for (int i = 0; i < row * col; i++) {
            // 5. 求当前数值的坐标
            cur_row = i / col;
            cur_col = i % col;
            
            x_l = cur_col;
            x_r = cur_col;
            y_t = cur_row;
            y_b = cur_row;

            sum = 0;

            // 6. 求当前数值的九宫格包围上下左右限
            if (cur_col - 1 >= 0) x_l = cur_col - 1;
            
            // col 为长度，不是索引，实际比索引大一，所以这里不加等号
            if (cur_col + 1 < col) x_r = cur_col + 1;
            if (cur_row - 1 >= 0) y_t = cur_row - 1;
            
            // 与 col 不加等号同理
            if (cur_row + 1 < row) y_b = cur_row + 1;

            // 7. 计算九宫格总和
            for (int y = y_t; y <= y_b; y++)
                for (int x = x_l; x <= x_r; x++)
                    sum += M[y][x];

            // 8. 给当前数值赋值为平滑后的数据
            smooth[cur_row][cur_col] = sum / ((y_b - y_t + 1) * (x_r - x_l + 1));
        }

        return smooth;
    }
};
```