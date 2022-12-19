### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int bfs(vector<vector<int>> &grid, int cur_i, int cur_j)
{
    
    grid[cur_i][cur_j] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(cur_i, cur_j));
    int ans = 1;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};

        for (int index = 0; index != 4; ++index)
        {
            int next_i = x.first + di[index], next_j = x.second + dj[index];
            if (next_i < 0 || next_i == grid.size() || next_j < 0 || next_j == grid[0].size() || grid[next_i][next_j]==0)
                continue;

            grid[next_i][next_j] = 0;
            q.push(make_pair(next_i, next_j));

            ans += 1;
        }
    }

    return ans;
}
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i != grid.size(); ++i)
        for (int j = 0; j != grid[0].size(); ++j){
            if(grid[i][j])
            ans = max(ans, bfs(grid, i, j));
        }
    return ans;

    }
};
```