### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 返回的结果，最大岛屿面积
        int res = 0;
        // i对应第几行，j对应第几列
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                res = max(res, dfs(grid, j, i));
            }
        }
        return res;
    }
    
    // dfs:深度优化搜索，递归方式
    // x对应第几列，y对应第几行
    int dfs(vector<vector<int>>& grid, int x, int y) {
        // 行列不对面积返回0
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) {
            return 0;
        }
        // 值为0表示不是岛屿
        if (grid[y][x] == 0) {
            return 0;
        }
        // 当前岛屿面积为1
        int sum = 1;
        int vx[] = {1, -1, 0, 0};// 4个元素表示4个方向，1为本岛屿右边，-1为本岛屿左边
        int vy[] = {0, 0, 1, -1};// 4个元素表示4个方向，1为本岛屿下边，-1为本岛屿上边
        // 本岛屿已计算过面积，避免递归到旁边的岛屿再递归回来，计算过面积的需要清零。
        grid[y][x] = 0;
        // 搜索四个方向是否还有岛屿
        for (int d = 0; d < 4; d ++) {
            int new_x = x + vx[d];
            int new_y = y + vy[d];
            sum += dfs(grid, new_x, new_y);
        }
        return sum;
    }
};


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y) {
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) {
        return 0;
    }
    if (grid[y][x] == 0) {
        return 0;
    }
    int sum = 1;
    int vx[] = {1, -1, 0, 0};
    int vy[] = {0, 0, 1, -1};
    grid[y][x] = 0;
    for (int d = 0; d < 4; d ++) {
        int new_x = x + vx[d];
        int new_y = y + vy[d];
        sum += dfs(grid, new_x, new_y);
    }
    return sum;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i ++) {
        for (int j = 0; j < grid[0].size(); j ++) {
            res = max(res, dfs(grid, j, i));
        }
    }
    return res;
}

int main() {
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(grid) << endl;
}





```