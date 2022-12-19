普通解法，直接暴力输出。需要特殊处理的就是右上角和左下角两个地方。

```
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int count = row * col;
        int flag = 1;
        int i = 0, j = 0;
        while (count > 0) {
            res.emplace_back(matrix[i][j]);
            int nextI = i - flag;
            int nextJ = j + flag;
            if (nextI < 0 && nextJ >= col) { //右上角
                i++;
                flag = -flag;
            } else if (nextI < 0 || nextI >= row) { //左下角的包含在这里
                j++;
                flag = -flag;
            } else if (nextJ < 0 || nextJ >= col) {
                i++;
                flag = -flag;
            } else {
                i = nextI;
                j = nextJ;
            }

            count--;
        }

        return res;
    }
};
```