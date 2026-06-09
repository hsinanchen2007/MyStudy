### 解题思路
- 最朴素的思路——驻点遍历；
- 效率太低

### 代码

```cpp
class Solution
{
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int mp[100][100];  //标志是否已经被访问
    int maxDistance(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int result = -1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!grid[i][j])
                    result = max(result, browse(i, j, grid));
                    //if (browse(i, j, grid) > result)
                     //   result = browse(i, j, grid);
            }
        }
        return result;
    }

    int browse(int x, int y, vector<vector<int>> &grid)
    {
        memset(mp, 0, sizeof mp);
        queue<pair<int, int>> que; //存放待访问的位置下标

        que.push({x, y});
        mp[x][y] = 1;
        while (!que.empty())
        {
            int xx = que.front().first;
            int yy = que.front().second;
            que.pop();
            for (auto di : dir)
            {
                int xxx = xx + di.first;
                int yyy = yy + di.second;
                if (xxx >= 0 && xxx < grid.size() && yyy >= 0 && yyy < grid[0].size())
                {
                    if(!mp[xxx][yyy]){
                        que.push({xxx, yyy});
                        mp[xxx][yyy] = 1;
                        if(grid[xxx][yyy])
                            return abs(xxx - x) + abs(yyy - y);
                    }
                }
            }
        }
        return -1;
    }
};
```