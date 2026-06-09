### 解题思路
使用两个点确定对角线，最开始两个点都在左下角， 点1先向上再向右走， 点2先向右再向上走， 每次两个点都只移动一步，即可确定一条对角线，然后对角线排序
最终两个点在右上角相遇


### 代码

```cpp
class Solution {
public:
    void diagnal_sort(vector<vector<int>>& mat, int row1, int col1, int row2, int col2)
    {
        if (row1 == row2 && col1 == col2) //仅一个元素
        {
            return;
        }

        //将矩阵对角线拷贝到v
        vector<int> v;
        v.reserve(row2 - row1 + 1);

        int tmp_row1 = row1;
        int tmp_col1 = col1;
        while (tmp_row1 <= row2)
        {
            v.push_back(mat.at(tmp_row1).at(tmp_col1));
            ++tmp_row1;
            ++tmp_col1;
        }

        //排序
        sort(v.begin(), v.end());

        //再拷贝回原矩阵
        int i = 0;
        while (row1 <= row2)
        {
            mat.at(row1).at(col1) = v.at(i);
            ++i;
            ++row1;
            ++col1;
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        //左下角
        int row1 = mat.size() - 1;
        int col1 = 0;
        int row2 = row1;
        int col2 = 0;

        //右上角
        int end_row = 0;
        int end_col = mat.at(0).size() - 1;

        while (col1 != end_col + 1)
        {
            //对角线排序
            diagnal_sort(mat, row1, col1, row2, col2);

            //移动两个点
            row1 == 0 ? ++col1 : --row1;
            col2 == end_col ? --row2 : ++col2;
        }

        return mat;
    }
};
```