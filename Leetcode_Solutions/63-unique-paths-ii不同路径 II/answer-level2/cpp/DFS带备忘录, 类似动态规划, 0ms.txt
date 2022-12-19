DFS, 带备忘录, 0ms

![0ms.png](https://pic.leetcode-cn.com/2b630b13afcde92c014bdea5018d09ceb50acd0ef740e165b9b42fb1673be0ee-0ms.png)

```
class Solution {
public:
    int rowNum;
    int colNum;
    const vector<vector<int>> steps = {{1, 0}, {0, 1}};
    vector<vector<int>> cache;
    int rstNum;

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        rowNum = obstacleGrid.size();
        colNum = obstacleGrid[0].size();
        cache.assign(rowNum, vector<int>(colNum, -1));
        rstNum = 0;
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        rstNum = DfsSearch(0, 0, obstacleGrid);
        return  rstNum;

    }

    int DfsSearch(int x, int y, vector<vector<int>>& obstacleGrid)
    {
        if (x == rowNum - 1 && y == colNum - 1) {
            return 1;
        }
        if (cache[x][y] != -1) {
            return cache[x][y];
        }
        int rst = 0;
        for (auto &step : steps) {
            int nx = x + step[0];
            int ny = y + step[1];
            if (nx < 0 || nx >= rowNum || ny < 0 || ny >= colNum) {
                continue;
            }
            if (obstacleGrid[nx][ny] == 1) {
                continue;
            }
            rst += DfsSearch(nx, ny, obstacleGrid);
        }
        return cache[x][y] = rst;
    }
};
```
