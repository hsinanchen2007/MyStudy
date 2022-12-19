```
class Solution {
public:
    int row, column;
    int surfaceArea(vector<vector<int>>& grid) {
        //初始表面积  立方体的数量 n * 6
        //减去上下叠加掉的数量 (n - 1) * 2
        //减去周围叠加的 SubStr
        if(grid.size()  == 0 || grid[0].size() == 0) return 0;
        int ans = 0;
        row = grid.size(), column = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0) continue;
                ans += 4 * grid[i][j] + 2;
                ans -= SubSur(grid, i, j);
            }
        }
        return ans;
        
    }
    int SubSur(vector<vector<int>>& grid, int i, int j){
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};
        int res = 0;
        for(int k = 0; k < 4; k++){
            int tmpx = i + x[k];
            int tmpy = j + y[k];
            if(tmpx >= 0 && tmpx < row && tmpy >= 0 && tmpy < column){
                res += min(grid[i][j], grid[tmpx][tmpy]);
            }
        }
        return res;
    }
};
```
