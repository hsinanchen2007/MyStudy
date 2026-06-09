### 解题思路
此题实际上是模拟的过程，实际上天际线就是行或者列的最大值，所以使用两个vector储存行和列的最大值。再一个循环来把每次可以加的地方加上去即可。

### 代码

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int colunm = grid[0].size();
        int count = 0;
        vector<int> maxvalrow(row,0);
        vector<int> maxvalcolunm(colunm,0);
        for(int i = 0;i < row;i++)
            for(int j = 0;j < colunm;j++)
            {
                if(maxvalrow[i] < grid[i][j]) maxvalrow[i] = grid[i][j];
                if(maxvalcolunm[j] < grid[i][j]) maxvalcolunm[j] = grid[i][j];
            }
        
        for(int i = 0;i < row;i++)
            for(int j = 0;j < colunm;j++)
            {
                if(grid[i][j] <= maxvalcolunm[j] && grid[i][j] <= maxvalrow[i])
                {
                    count += min(maxvalcolunm[j] - grid[i][j],maxvalrow[i] - grid[i][j]);
                }
            }
        return count;
    }
};
```