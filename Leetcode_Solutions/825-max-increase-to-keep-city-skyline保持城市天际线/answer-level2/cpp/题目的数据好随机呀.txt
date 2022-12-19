### 解题思路
同样的代码交了两边 一个执行用时20ms一个执行用时4ms 爷哭了
### 代码

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r[51]={0}, c[51]={0}, ans = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            r[i] = grid[i][0];
            for (int j = 1; j < grid[i].size(); j++)r[i] = max(r[i], grid[i][j]);
        }
         for (int i = 0; i < grid[0].size(); i++)
        {
            c[i] = grid[0][i];
            for (int j = 1; j < grid[i].size(); j++)c[i] = max(c[i], grid[j][i]);
        }
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                ans += min(r[i], c[j])-grid[i][j];
        return ans;
    }
};
```