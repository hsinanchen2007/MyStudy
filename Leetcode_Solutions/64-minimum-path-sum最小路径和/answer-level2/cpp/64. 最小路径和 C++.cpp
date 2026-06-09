### 解题思路
二维动态规划

### 代码

```cpp
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {

        if (grid.empty())
        {
            return 0;
        }

        int m = grid.size();
        int n = grid.at(0).size();

        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i == m - 1 && j == n - 1) //到达终点
                {
                    dp.at(i).at(j) = grid.at(i).at(j);
                }
                else if (i == m - 1) //到达下边界 只能向右走
                {
                    dp.at(i).at(j) = grid.at(i).at(j) + dp.at(i).at(j + 1);
                }
                else if (j == n - 1) //到达右边界，只能向下走
                {
                    dp.at(i).at(j) = grid.at(i).at(j) + dp.at(i + 1).at(j);
                }
                else //既可以向下 也可以向右
                {
                    //比较两个方向的下一步到终点的最小路径和 选更小的
                    dp.at(i).at(j) = grid.at(i).at(j) + min(dp.at(i).at(j + 1), dp.at(i + 1).at(j));
                }
            }
        }

        return dp.at(0).at(0);
    }
};
```