### 解题思路
此处撰写解题思路

### 代码

```cpp
先找到数组中0元素所在的位置，然后依次将数组中0所在的位置的行和列清零。

class Solution {
private:
    vector<pair<int, int>> findZeroPosition(vector<vector<int>>& matrix)
    {
        vector<pair<int, int>> zero;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    pair<int, int> p(i, j);
                    zero.push_back(p);
                }
            }
        }

        return zero;
    }

    void FillMatrix(vector<vector<int>>& matrix, vector<pair<int, int>>& zero)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < zero.size(); i++)
        {
            int row = zero[i].first;
            int col = zero[i].second;

            for (int i = 0; i < cols; i++)
                matrix[row][i] = 0;
            for (int i = 0; i < rows; i++)
                matrix[i][col] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return;

        vector<pair<int, int>> zero = findZeroPosition(matrix);
        FillMatrix(matrix, zero);
    }
};
```