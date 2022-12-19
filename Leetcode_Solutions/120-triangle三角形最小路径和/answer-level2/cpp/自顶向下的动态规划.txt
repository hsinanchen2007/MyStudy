状态转移方程如下：

`memo[i][j] = min(memo[i-1][j-1],memo[i-1][j]) + triangle[i][j]`

memo是存储状态的数组，memo[i][j]表示第(i, j)个位置可取得的最小值。上述状态转移方程的含义是，位置(i, j)处的和最小值等于上一行前一列(i-1,j-1)和上一行当前列(i-1, j)之间最小值加上当前位置上三角形的值。

至于为什么是(i-1,j-1)和(i-1, j)这两个坐标，是因为第i行的依赖于前一行的结果，又规定了只能往相邻格子走，通过观察得知，上一行相邻的位置正是公式里(i-1,j-1)和(i-1, j)。

代码如下：

```c
class Solution {
public:

    // memo[i][j] = min(memo[i-1][j-1],memo[i-1][j]) + triangle[i][j]
    int minimumTotal(vector<vector<int>> &triangle) {
        // 计算行和列
        int row = triangle.size();
        int col = 0;
        if (row)
            col = triangle[row - 1].size();
        // 初始化一个存储结果的数组，这里我简单的设置为row*col的二维数组，因为
        // 从状态转移方程得知，有两个维度的坐标。
        vector<vector<int>> memo(row, vector<int>(col, 0));

        // 初始化第0行第0个元素为三角形的第一个元素
        memo[0][0] = triangle[0][0];
        // 从第1行开始，对每一行求memo[i][j]
        for (int i = 1; i < row; i++) {
            // 求memo[i][j]
            for (int j = 0; j < triangle[i].size(); j++) {
                // 取上一行相邻格子的值，因为j-1可能小于0或者大于上一行的元素个数
                // 所以要做边界检查。
                int a = (j - 1 >= 0) ? memo[i - 1][j - 1] : INT32_MAX; //memo[i-1][j-1]
                int b = (j < triangle[i - 1].size()) ? memo[i - 1][j] : INT32_MAX;
                // 状态转移方程
                memo[i][j] = min(a, b) + triangle[i][j];
            }
        }

        // 扫描最后一行，求最小值
        // 因为从转台转移方程得知，最大值可能最最后一行的某个位置中
        int res = INT32_MAX;
        for (int j = 0; j < col; j++) {
            res = min(res, memo[row - 1][j]);
        }

        return res;
    }
};
```

如果不理解状态转移方程，跟着代码走一遍就行。