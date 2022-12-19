### 解题思路
首先确定对角线的个数，为一行的长度 + 一列的长度 - 1
其次对角线上元素的行号 + 列号是一个相等的数，即 r + c相同
最后按次遍历所有对角线
### 代码

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        int rows = matrix.size() - 1, columns = matrix[0].size() - 1;
        int start_row = 0, start_column = 0;
        int turn = 0, max_turn = rows + columns + 1;
        vector<int> res;
        while (turn < max_turn) {
            // 本轮turn超过最大列时，证明有一行的数据已经全部加入
            if (turn > columns) {
                ++start_row;
            }
            // 当本轮turn超过最大行时，证明有一列的数据已经全部加入
            if (turn > rows) {
                ++start_column;
            }
            // 根据对角线先 r + c = turn进行对角线元素插入
            if (turn & 1) {
                for (int r = start_row, c = turn - start_row; r <= rows && c >= start_column; ++r, --c) {
                    res.push_back(matrix[r][c]);
                }
            } else {
                for (int r = turn - start_column, c = start_column; r >= start_row && c <=  columns; --r, ++c) {
                    res.push_back(matrix[r][c]);
                }
            }
            ++turn;
        }
        return res;
    }
};
```