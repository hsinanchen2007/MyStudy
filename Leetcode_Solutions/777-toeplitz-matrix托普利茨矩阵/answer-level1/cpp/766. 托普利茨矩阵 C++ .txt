### 解题思路
方法1：查看每条对角线元素是否相同 （无法处理进阶要求）  时间复杂度O(M*N)  空间复杂度O(1)


### 代码

```cpp
class Solution {
public:

    //对角线元素相同： 即对角线 最大值 == 最小值
    bool diagonal_equal(const vector<vector<int>>& matrix, int row, int col)
    {
        int min = INT_MAX;
        int max = INT_MIN;
        while (row < matrix.size() && col < matrix.at(0).size())
        {
            if (matrix.at(row).at(col) < min)
            {
                min = matrix.at(row).at(col);
            }

            if (matrix.at(row).at(col) > max)
            {
                max = matrix.at(row).at(col);
            }

            ++row;
            ++col;
        }
        return min == max;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        //纵向起始 对角线
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (!diagonal_equal(matrix, i, 0))
                return false;
        }
        
        //横向起始 对角线
        for (int i = 1; i < matrix.at(0).size(); ++i)
        {
            if (!diagonal_equal(matrix, 0, i))
                return false;
        }

        return true;
    }
};
```