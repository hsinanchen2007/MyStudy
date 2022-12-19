### 解题思路
按圈旋转 空间复杂度O(1)
每圈按四个点一组，分组做顺时针旋转

### 代码

```cpp
class Solution {
public:
    void rotate_edge(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2)
    {
        //方阵边缘 每四个点一组，分成col2 - col1组
        for (int i = 0; i < col2 - col1; ++i)
        {
            int tmp = matrix.at(row1).at(col1 + i);
            matrix.at(row1).at(col1 + i) = matrix.at(row2 - i).at(col1);
            matrix.at(row2 - i).at(col1) = matrix.at(row2).at(col2 - i);
            matrix.at(row2).at(col2 - i) = matrix.at(row1 + i).at(col2);
            matrix.at(row1 + i).at(col2) = tmp;
        }
    }

    void rotate(vector<vector<int>>& matrix) {

        int row1 = 0;
        int col1 = 0;
        int row2 = matrix.size() - 1;
        int col2 = matrix.at(0).size() - 1;

        while (row1 < row2) //等于的情况只有一个点了，不用处理 (行列为奇数)
        {
            rotate_edge(matrix, row1++, col1++, row2--, col2--);
        }
    }
};
```