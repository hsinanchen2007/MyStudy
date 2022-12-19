浅显易懂，先按照主对角线交换，再按照纵向的中间轴左右交换即可

```c++
class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int j = 0; j < n / 2; j++)
        {
            for (int i = 0; i < m; i++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
```