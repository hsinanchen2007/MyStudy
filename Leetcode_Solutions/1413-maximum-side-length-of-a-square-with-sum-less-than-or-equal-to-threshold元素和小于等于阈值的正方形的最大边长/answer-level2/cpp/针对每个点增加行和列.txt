比较暴力的方法：

对于每一个点，定义 `(row, col)`, 为起始点，`(curRow, curCol)`为当前点

不断累加当前行和当前列((curRow, curCol)会被多加一次，注意去重)

直到 `curRow >= mat.size(), curCol >= mat[0].size()`

由于 mat[i][j] >= 0，所以累加过程进行判断，大于 threshold 直接返回。


```
class Solution {
   public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                helper(mat, i, j, threshold);
            }
        }
        return _max;
    }

   private:
    void helper(vector<vector<int>>& mat, int row, int col, int threshold) {
        int curRow = row;
        int curCol = col;
        int sum = 0;
        while (curRow < mat.size() && curCol < mat[0].size()) {
            // 添加新的列
            for (int i = row; i <= curRow; i++) {
                sum += mat[i][curCol];
                if (sum > threshold) return;
            }
            // 添加新的行
            for (int i = col; i < curCol; i++) {
                sum += mat[curRow][i];
                if (sum > threshold) return;
            }
            if (curRow - row + 1 > _max) _max = curRow - row + 1;
            curRow++;
            curCol++;
        }
    }

    int _max = 0;
};
```
