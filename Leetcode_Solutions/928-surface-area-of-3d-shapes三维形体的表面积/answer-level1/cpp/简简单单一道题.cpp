每统计一个位置[i][j] 就去判断他的左边和上边有没有矩形，然后减去覆盖的就行了。
注意不要产生负数就行
```
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int count = 0;
        if (grid.empty())
        {
            return 0;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int b = j == 0 ? 0 : min(grid[i][j], grid[i][j - 1]);
                int a = i == 0 ? 0 : min(grid[i][j], grid[i - 1][j]);
                int c = grid[i][j] == 0 ? 0 : grid[i][j] - 1;
                count += grid[i][j] * 6 - (c + a + b) * 2;
            }
        }
        return count;
    }
};
```
