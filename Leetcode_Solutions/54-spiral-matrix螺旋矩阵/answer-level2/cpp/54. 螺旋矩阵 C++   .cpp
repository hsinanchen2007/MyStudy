### 解题思路
矩阵分圈处理  时间复杂度O(N) 空间复杂度O(1)
一圈一圈打印，大圈，小圈，直到最里面
缩圈 就是左上角顶点行列都+1 与 右下角顶点行列都-1
有特殊情况 一行或一列

### 代码

```cpp
class Solution {
public:

    //顺时针打印
    //row1、col1为左上角行、列索引
    //row1、col1为右下角行、列索引
    void clockwise_print(const vector<vector<int>>& matrix, int row1, int col1, int row2, int col2, vector<int>& v)
    {
        //特殊情况 仅一行 或 一列
        if (row1 == row2) //仅一行
        {
            while (col1 <= col2)
            {
                v.push_back(matrix.at(row1).at(col1));
                ++col1;
            }
            return;
        }
        else if (col1 == col2) //仅一列
        {
            while (row1 <= row2)
            {
                v.push_back(matrix.at(row1).at(col1));
                ++row1;
            }
            return;
        }


        //矩阵
        //从左到右
        int tmp_col1 = col1;
        while (tmp_col1 != col2)
        {
            v.push_back(matrix.at(row1).at(tmp_col1));
            ++tmp_col1;
        }

        //从上到下
        int tmp_row1 = row1;
        while (tmp_row1 != row2)
        {
            v.push_back(matrix.at(tmp_row1).at(col2));
            ++tmp_row1;
        }

        //从右到左
        while (col2 != col1)
        {
            v.push_back(matrix.at(row2).at(col2));
            --col2;
        }

        //从下到上
        while (row2 != row1)
        {
            v.push_back(matrix.at(row2).at(col1));
            --row2;
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if (matrix.empty())
        {
            return vector<int>();
        }

        int row1 = 0;
        int col1 = 0; 
        int row2 = matrix.size() - 1; 
        int col2 = matrix.at(0).size() - 1;

        vector<int> v;
        v.reserve(matrix.size() * matrix.at(0).size());

        while (row1 <= row2 && col1 <= col2) //只要有行索引或列索引相互交错，就终止
        {
            clockwise_print(matrix, row1++, col1++, row2--, col2--, v);
        }

        return v;
    }
};
```