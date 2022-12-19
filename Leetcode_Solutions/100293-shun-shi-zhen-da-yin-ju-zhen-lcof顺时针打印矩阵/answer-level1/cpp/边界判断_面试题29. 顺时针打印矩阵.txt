### 解题思路
    /*
     * 边界判断法
     *
     * 顺时针打印矩阵，即对矩阵顺时针遍历，
     * 矩阵是矩形的，所以需要考虑四个边界条件。
     *
     * 1. 首先设定上(up)下(down)左(left)右(right)四个边界，
     *    并分别初始化为up=left=0, down=行数, right=列数。
     * 2. 向右遍历到矩阵最右边的点，将这些点push到结果数组中，
     *    此时第一行已经遍历完，将上边界up更新，即up++，
     *    同时判断上下边界是否交错，交错则跳出循环，不交错则继续。
     * 3. 向下遍历到矩阵最下边的点，将这些点push到结果数组中，
     *    此时最右边一列已经遍历完，将右边界right更新，即right--，
     *    同时判断左右边界是否交错，交错则跳出循环，不交错则继续。
     * 4. 向左遍历到矩阵最左边的点，将这些点push到结果数组中，
     *    此时最下边的一行已经遍历完，将下边界down更新，即down--，
     *    同时判断左右边界是否交错，交错则跳出循环，不交错则继续。
     * 5. 向上遍历到矩阵的上边界最左边的点，将这些点push到结果数组中，
     *    此时最左边的一行已经遍历完，将左边界left更新，即left++，
     *    同时判断上下边界是否交错，交错则跳出循环，不交错则继续。
     * 6. 循环以上步骤，直到某两条边界交错，跳出循环，返回结果数组。
     * */
### 代码

```cpp
std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    std::vector<int> ans;

    if (matrix.empty()) {
        return ans;
    }

    // 初始化上下边界，上下边界表示行数
    int up = 0, down = matrix.size() - 1;

    // 初始化左右边界，左右边界表示列数
    int left = 0, right = matrix[0].size() - 1;

    // 当上下左右边界满足条件时，不断循环
    while (up < matrix.size() && down >= 0 && left < matrix[0].size() && right >= 0) {
        // 上面行向右遍历
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[up][i]);
        }
        // 上边界up更新
        if (++up > down) {
            break;
        }

        // 右边列向下遍历
        for (int i = up; i <= down; i++) {
            ans.push_back(matrix[i][right]);
        }
        // 右边界right更新
        if (--right < left) {
            break;
        }

        // 下边行向左遍历
        for (int i = right; i >= left; i--) {
            ans.push_back(matrix[down][i]);
        }

        // 下边界更新
        if (--down < up) {
            break;
        }

        // 左边列向上遍历
        for (int i = down; i >= up; i--) {
            ans.push_back(matrix[i][left]);
        }

        // 左边界更新
        if (++left > right) {
            break;
        }
    }

    return ans;
}
```