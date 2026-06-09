### 解题思路
没啥可写的...

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n;
        int count = 0;
        for (int i=0; i<m; i++)
        {
            n = grid[i].size();
            for (int j=0; j<n; j++)
            {
                if(grid[i][j] < 0)
                    count++;
            }
        }
        return count;
    }
};
```