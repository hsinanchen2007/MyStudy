### 解题思路
1、二分查找 所有可能通过的时间;
2、使用DFS去进行验证，(注意这里千万不要使用回溯，会大大提供时间复杂度，导致超时);

### 代码

```cpp
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int maxCount = INT_MIN;
        int minCount = INT_MAX;
        for (vector<int> vecInt : grid) {
            for (int i : vecInt) {
                maxCount  = max(maxCount, i);
                minCount = min(minCount, i);
            }
        }
        int curCount = 0;
        while (minCount < maxCount) {
            curCount = (maxCount + minCount) / 2;
            cout << "minCount:" <<minCount <<" maxCount:"<< maxCount <<" curCount:" << curCount << endl;
            bool flag = isOk(grid, curCount);
            cout << "flag :" << flag <<endl;
            if (flag) {
                maxCount = curCount;
            } else {
                minCount = curCount + 1;
            }
        }
        return minCount;
    }

    bool isOk(vector<vector<int>>& grid, int curCount) {
        vector<vector<int>> isArrived(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > curCount) {
                    isArrived[i][j] = 1;
                }
                cout << isArrived[i][j] << " ";
            }
            cout << endl;
        }
        if (isArrived[0][0] == 1) {
            return false;
        }

        bool isExist = false;
        dfs(grid, isArrived, 0, 0, isExist);
        return isExist;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& isArrived, int x, int y, bool& flag) {
        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
            flag = true;
        }
        if (x + 1 < grid.size() && isArrived[x + 1][y] == 0) {
            isArrived[x + 1][y] = 1;
            dfs(grid, isArrived, x + 1, y, flag);
//            isArrived[x + 1][y] = 0;
        }
        if (x - 1 >= 0 && isArrived[x - 1][y] == 0) {
            isArrived[x - 1][y] = 1;
            dfs(grid, isArrived, x - 1, y, flag);
//            isArrived[x - 1][y] = 0;
        }
        if (y + 1 < grid[0].size() && isArrived[x][y + 1] == 0) {
            isArrived[x][y + 1] = 1;
            dfs(grid, isArrived, x, y + 1, flag);
//            isArrived[x][y + 1] = 0;
        }
        if (y - 1 >= 0 && isArrived[x][y - 1] == 0) {
            isArrived[x][y - 1] = 1;
            dfs(grid, isArrived, x, y - 1, flag);
//            isArrived[x][y - 1] = 0;
        }
        return;
    }
};
```