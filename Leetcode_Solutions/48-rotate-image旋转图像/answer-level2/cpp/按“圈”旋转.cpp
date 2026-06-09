### 解题思路
将矩阵旋转分解成为：从最外圈到最内圈，每个圈旋转90度。将每个圈的旋转分解为若干组四个对应元素的旋转，可利用公式matrix[row][col]->matrix[col][n - row - 1]。
执行用时: 0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗: 8.4 MB, 在所有 C++ 提交中击败了100.00%的用户

![leetcode48 (2).png](https://pic.leetcode-cn.com/30383b2f9a978c0caa68bb460d657d905e116b48e89de92a14d3ee4ea03595a0-leetcode48%20\(2\).png)


### 代码


```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for (int row = 0; row < n / 2; ++row)
        {
            for (int col = row; col < n - row - 1; ++col)
            {
                rotate_90_degrees(matrix, n, row, col);
            }
        }
    }

    void rotate_90_degrees(vector<vector<int>>& matrix, const int n, int row, int col)
    {
        int temp1;
        int temp2;
        int tempRow;

        temp1 = matrix[col][n - row - 1];
        matrix[col][n - row - 1] = matrix[row][col];
        tempRow = row;
        row = col;
        col = n - tempRow - 1;
        for (int count = 0; count < 2; ++count)
        {
            temp2 = matrix[col][n - row - 1];
            matrix[col][n - row - 1] = temp1;
            temp1 = temp2;
            tempRow = row;
            row = col;
            col = n - tempRow - 1;
        }
        matrix[col][n - row - 1] = temp1;
        tempRow = row;
        row = col;
        col = n - tempRow - 1;
    }
};
```