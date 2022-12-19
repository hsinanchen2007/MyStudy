先左右翻转矩阵，再沿斜对角线翻转矩阵
```
class Solution {
public:
    void swap(vector<int> &row, int i, int j) {
        int tmp = row[i];
        row[i] = row[j];
        row[j] = tmp;
    }
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[i].size() / 2 ; j++) {
                swap(matrix[i], j, (int)matrix[i].size() - j - 1);
            }
        }
        int row = (int)matrix.size();
        int col = (int)matrix[0].size();
        for (int i = 0; i < (int)matrix.size() - 1; i++) {
            for (int j = 0; j < (int)matrix[i].size() - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[row - 1 - j][col - 1 - i];
                matrix[row - 1 - j][col - 1 -i] = tmp;
            }
        }
    }
};

```
