## 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        const int rows = matrix.size();
        if (rows == 0)
            return res;
        const int cols = matrix[0].size();
        vector<int> rowMin(rows, INT_MAX);
        vector<int> colMax(cols, 0);
        // 求解每行的最小值
        for (int i = 0; i < rows; i++) {
            int &m = rowMin[i];
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] < m)
                    m = matrix[i][j];
            }
        }
        // 求解每列的最大值
        for (int i = 0; i < cols; i++) {
            int &m = colMax[i];
            for (int j = 0; j < rows; j++) {
                if (matrix[j][i] > m)
                    m = matrix[j][i];
            }
        }
        // 遍历每个位置，确认是否符合答案要求
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }        
        return res;
    }
};
```
