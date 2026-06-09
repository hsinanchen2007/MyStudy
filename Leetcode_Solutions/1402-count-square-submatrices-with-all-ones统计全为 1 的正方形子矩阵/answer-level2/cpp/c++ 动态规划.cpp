动态规划，判断当前位置是几个正方形数组的右下角顶点。

当前点为正方形数组的右下角顶点必须满足，左边一个元素为正方形右下角顶点，上方一个元素为正方形右下角顶点，左上侧点为正方形右下角顶点。

代码：

```c++
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!matrix[i][j]) continue;
                if (i && j)  matrix[i][j] = min(min(matrix[i][j - 1], matrix[i - 1][j]), matrix[i - 1][j - 1]) + 1;
                res += matrix[i][j];
            }
        }
        return res;
    }
};
```