1.BFS从陆地开始搜索
2.被感染，标记为#
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019.9.20
*/

class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        gridCopy = grid;
        nums = 0;
        for (int i = 0; i < gridCopy.size(); ++i) {
            for (int j = 0; j < gridCopy.at(i).size(); j++) {
                if (gridCopy.at(i).at(j) == '1') {
                    nums++;
                    numIslandsBfs(gridCopy, i, j);
                }
            }
        }
        return nums;
    }
private:
    void numIslandsBfs(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int, int>> paths;
        paths.push({i, j});
        while (!paths.empty()) {
            pair<int, int> data = paths.front();
            paths.pop();
            int row = data.first;
            int col = data.second;

            grid[row][col] = '#';

            if (row - 1 >= 0 && grid.at(row - 1).at(col) == '1') {
                paths.push({row - 1, col});
                grid[row - 1][col] = '#';
            }
            if (col - 1 >= 0 && grid.at(row).at(col - 1) == '1') {
                paths.push({row, col - 1});
                grid[row][col - 1] = '#';
            }
            if (row + 1 < grid.size() && grid.at(row + 1).at(col) == '1') {
                paths.push({row + 1, col});
                grid[row + 1][col] = '#';
            }
            if (col + 1 < grid.at(i).size() && grid.at(row).at(col + 1) == '1') {
                paths.push({row, col + 1});
                grid[row][col + 1] = '#';
            }
        }
    }
private:
    int nums;
    vector<vector<char>> gridCopy;
};
```
