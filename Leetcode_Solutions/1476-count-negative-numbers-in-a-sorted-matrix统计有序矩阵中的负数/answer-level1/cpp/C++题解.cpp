## [Contest 176](https://leetcode-cn.com/contest/weekly-contest-176/)

### [5340. 统计有序矩阵中的负数](https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/)

### 题解
  + 直接统计即可
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)
  
### 代码
```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] < 0)
                {
                    res += grid[i].size() - j;
                    break;
                }
            }
        return res;
    }
};
```