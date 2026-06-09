### 解题思路


### 代码

```cpp
class Solution {
public:

    //方法1：直接法
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        if(matrix.empty())
        {
            return vector<int>();
        }

        int m = matrix.size(); //行
        int n = matrix.at(0).size(); //列

        int size = m * n;
        vector<int> v;
        v.reserve(size);

        int row = 0;
        int col = 0;

        int direction = 0;

        for(int i = 0; i < size; ++i)
        {
            v.push_back(matrix.at(row).at(col));

            if (direction == 0) //从左下往右上
            {
                if (row == 0 && col < n - 1) //仅行减到头
                {
                    ++col;
                    direction = 1;
                }
                else if (col == n - 1) //列加到头
                {
                    ++row;
                    direction = 1;
                }
                else
                {
                    --row;
                    ++col;
                }
            }
            else if (direction == 1) //从右上往左下
            {
                if(row < m - 1 && col == 0) //仅列减到头
                {
                    ++row;
                    direction = 0;
                }
                else if (row == m - 1) //行加到头
                {
                    ++col;
                    direction = 0;
                }
                else
                {
                    ++row;
                    --col;
                }
            }
        }
        return v;
    }


    //方法2： 打印两个点之间的连线  即对角线
    //若fromup为true, 则从右上到左下遍历，反之则从左下到右上遍历
    //左下的点为 (row1, col1)
    //右上的点为 (row2, col2)
    void traverse_diagonal(const vector<vector<int>>& matrix, int row1, int col1, int row2, int col2, bool fromup, vector<int>& v)
    {
        if (fromup) //从右上到左下遍历
        {
            while (row2 <= row1)
            {
                v.push_back(matrix.at(row2).at(col2));
                ++row2;
                --col2;
            }
        }
        else //从左下到右上遍历
        {
            while (row1 >= row2)
            {
                v.push_back(matrix.at(row1).at(col1));
                --row1;
                ++col1;
            }
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        if (matrix.empty())
        {
            return vector<int>();
        }

        int m = matrix.size(); //行
        int n = matrix.at(0).size(); //列

        int size = m * n;
        vector<int> v;
        v.reserve(size);

        int row1 = 0;
        int col1 = 0;
        int row2 = 0;
        int col2 = 0;

        bool from_up = false; //初始为从左下到右上

        for(int i = 0; i < m + n - 1; ++i)
        {
            traverse_diagonal(matrix, row1, col1, row2, col2, from_up, v);
            
            from_up = !from_up; //改变遍历方向

            //两个点移动
            row1 != m - 1 ? ++row1 : ++col1;

            col2 != n - 1 ? ++col2 : ++row2;
        }

        return v;
    }
};