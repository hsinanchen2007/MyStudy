可以把这个二维数组想像成一个n*m的环,推进k次就是把环的起点后移k位
```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size()));
        int tmp;
        int c, r;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                tmp = i * grid[0].size() + j + k;
                r = (tmp  / grid[0].size()) % grid.size();
                c = tmp % grid[0].size();
                res[r][c] = grid[i][j];
            }
        }
        return res;
    }
};
```
