### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row_start = 0, row_end = n - 1;
        int col_start = 0, col_end = n - 1;
        vector<vector<int>> res(n, vector<int>(n));
        int k = 1;
        while (row_start <= row_end && col_start <= col_end) {
            for (int col = col_start; col <= col_end; ++col) {
                res[row_start][col] = k++;
            }

            for (int row = row_start + 1; row <= row_end; ++row) {
                res[row][col_end] = k++;
            }

            if (row_start < row_end && col_start < col_end) {
                for (int col = col_end - 1; col >= col_start; --col) res[row_end][col] = k++;
                for (int row = row_end - 1; row > row_start; --row) res[row][col_start] = k++;
            }
            row_start++;
            row_end--;
            col_start++;
            col_end--;
        }
        return res;
    }
};
```