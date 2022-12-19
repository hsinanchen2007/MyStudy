做法很简单，就是绕着外围一圈圈读取
在读取过程中分为四个部分：
1. 上面一行的读取
2. 右边一列的读取
3. 下面一行的读取
4. 左边一列的读取

需要注意的是读取的范围要注意不要重复或者越界

```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return {};
        int col = matrix[0].size();
        int total = row * col;
        if (total == 0)
            return {};
        vector<int> res(row * col);
        int halfRow = (row - 1) / 2;
        int cnt = 0;

        for (int i = 0;i <= halfRow;i++){
            int colLimit = col - i - 1;
            for (int j = i;cnt < total && j <= colLimit;j++){
                res[cnt++] = matrix[i][j];
            }
            int rowLimit = row - i - 1;
            for (int j = i + 1;cnt < total && j <= rowLimit;j++){
                res[cnt++] = matrix[j][colLimit];
            }
            for (int j = colLimit - 1;cnt < total && j >= i;j--){
                res[cnt++] = matrix[rowLimit][j];
            }
            for (int j = rowLimit - 1;cnt < total && j > i;j--){
                res[cnt++] = matrix[j][i];
            }
        }
        return res;
    }
};
```

