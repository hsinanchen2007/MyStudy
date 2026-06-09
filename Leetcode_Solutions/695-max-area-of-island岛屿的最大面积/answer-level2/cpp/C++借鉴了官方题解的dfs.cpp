class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0 ; i < grid.size() ; i++)
            for(int j = 0 ; j < grid[0].size() ; j++){
                res = max(res, dfs(grid, i, j));
            }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;
        int res = 1;
        int direct_i[] = {0,1,0,-1};
        int direct_j[] = {1,0,-1,0};
        for(int k = 0 ; k < 4 ; k++){
            res += dfs(grid, i+direct_i[k], j+direct_j[k]);
        }
        return res;
    }
};