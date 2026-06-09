### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    //画重点！！！仔细想想，这不就是海岛问题吗？亏我还想了半天动态规划啥的。问题抽象很重要啊。
    int movingCounts(int i, int j, int k, vector<vector<int>>& grid) {
        if (i/10+i%10+j/10+j%10>k || i>=grid.size() || j>=grid[0].size()) return 0;
        int count = 0;
        if (grid[i][j] > 0)
        {
            int temp = grid[i][j];
            grid[i][j] = 0;
            count += movingCounts(i+1, j, k, grid)+movingCounts(i, j+1, k, grid)+temp;
        }
        return count;
    }
public:
    int movingCount(int m, int n, int k) {
        if ((m == 1 && n == 1) || k == 0) return 1;
        vector<vector<int>> grid(m, vector<int>(n, 1));
        return movingCounts(0, 0, k, grid);
    }
};
```