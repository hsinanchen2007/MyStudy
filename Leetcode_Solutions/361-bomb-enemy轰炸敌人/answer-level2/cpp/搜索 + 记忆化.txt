搜索，记录横向、纵向能伤害到的敌人，相邻都是 0 的格子，可以直接取已缓存的值。

```c++ []
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int res = 0;
        if (grid.empty()) return res;
        vector<vector<int>> rmemo(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> cmemo(grid.size(), vector<int>(grid[0].size(), 0));
        
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] != '0') continue;
                if (col > 0 && grid[row][col - 1] == '0') {
                    rmemo[row][col] = rmemo[row][col - 1];
                } else {
                    rmemo[row][col] = killedOnRow(grid, row, col);
                }
                    
                if (row > 0 && grid[row - 1][col] == '0') {
                    cmemo[row][col] = cmemo[row - 1][col];
                } else {
                    cmemo[row][col] = killedOnCol(grid, row, col);
                }
                
                res = max(rmemo[row][col] + cmemo[row][col], res);
            }
        }
        
        return res;
    }
    
private:
    int killedOnRow(vector<vector<char>> &grid, int row, int col) { 
        int res = 0;
        int l = col - 1, r = col + 1;   
        while (l >= 0 && grid[row][l] != 'W') {
            res += grid[row][l--] == 'E' ? 1 : 0;
        }
        while (r < grid[row].size() && grid[row][r] != 'W') {
            res += grid[row][r++] == 'E' ? 1 : 0;
        }
        
        return res;
    }
    
    int killedOnCol(vector<vector<char>> &grid, int row, int col) {
        int res = 0;
        int l = row - 1, r = row + 1;
        while (l >= 0 && grid[l][col] != 'W') {
            res += grid[l--][col] == 'E' ? 1 : 0;
        }
        while (r < grid.size() && grid[r][col] != 'W') {
            res += grid[r++][col] == 'E' ? 1 : 0;
        }

        return res;
    }
};
```