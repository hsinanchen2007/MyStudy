### 解题思路
一圈一圈填值 时间复杂度O(N)  空间复杂度O(1)

### 代码

```cpp
class Solution {
public:

    //顺时针填充
    //最后一个参数为引用，在函数内部改变值，初始化为1，即可实现从1打印到n
    void clockwise_fill(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2, int& init_val)
    {
        //特殊情况 仅一行 或 一列
        if (row1 == row2) //仅一行
        {
            while (col1 <= col2)
            {
                matrix.at(row1).at(col1) = init_val;
                ++init_val;
                ++col1;
            }
            return;
        }
        else if (col1 == col2) //仅一列
        {
            while (row1 <= row2)
            {
                matrix.at(row1).at(col1) = init_val;
                ++init_val;
                ++row1;
            }
            return;
        }

        //矩阵
        //从左到右
        int tmp_col1 = col1;
        while (tmp_col1 != col2)
        {
            matrix.at(row1).at(tmp_col1) = init_val;
            ++init_val;
            ++tmp_col1;
        }

        //从上到下
        int tmp_row1 = row1;
        while (tmp_row1 != row2)
        {
            matrix.at(tmp_row1).at(col2) = init_val;
            ++init_val;
            ++tmp_row1;
        }

        //从右到左
        while (col2 != col1)
        {
            matrix.at(row2).at(col2) = init_val;
            ++init_val;
            --col2;
        }

        //从下到上
        while (row2 != row1)
        {
            matrix.at(row2).at(col1) = init_val;
            ++init_val;
            --row2;
        }
    }

    vector<vector<int>> generateMatrix(int n) {

        //构造矩阵
        vector<vector<int>> matrix;
        matrix.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            matrix.push_back(vector<int>(n));
        }

        int row1 = 0;
        int col1 = 0;
        int row2 = matrix.size() - 1;
        int col2 = matrix.at(0).size() - 1;

        int init_val = 1;

        while (row1 <= row2 && col1 <= col2) //只要有行索引或列索引相互交错，就终止
        {
            clockwise_fill(matrix, row1++, col1++, row2--, col2--, init_val);
        }
        
        return matrix;
    }
};
```