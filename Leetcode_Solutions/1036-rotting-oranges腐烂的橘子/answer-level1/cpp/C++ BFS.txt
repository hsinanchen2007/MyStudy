### 解题思路
这题可不是简单难度啊……

### 代码

```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> map;
        int dir[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        int times = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                    map.push(make_pair(j, i));
            }
        }

        while (!map.empty())
        {
            int size = map.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> point = map.front();
                map.pop();
                for (int i = 0; i < 4; i++)
                {
                    pair<int, int> newPoint(point.first + dir[i][0], point.second + dir[i][1]);
                    if (newPoint.first >= grid[0].size() || newPoint.first < 0 || newPoint.second >= grid.size() || newPoint.second < 0)
                        continue;
                    if (grid[newPoint.second][newPoint.first] != 1)
                        continue;
                    grid[newPoint.second][newPoint.first] = 2;
                    map.push(newPoint);
                }     
                grid[point.second][point.first] = 2;
            }
            times++;
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return times > 0 ? times - 1 : times;
    }
};
```