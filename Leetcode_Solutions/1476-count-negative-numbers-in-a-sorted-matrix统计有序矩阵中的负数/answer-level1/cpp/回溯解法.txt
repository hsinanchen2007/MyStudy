```
    int solve(int r1, int r2, int c1, int c2, vector<vector<int>>& grid){
        if(r1 >= r2 || c1 >= c2 ) return 0;
        int r, c;
        for(r = r1, c = c1; r < r2 && c < c2 && grid[r][c] >= 0; r++, c++);
        int ans = (r2 - r)*(c2 - c); 
        ans += solve(r, r2, c1, c, grid); 
        ans += solve(r1, r, c, c2, grid); 
        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        return solve(0, grid.size(), 0, grid[0].size(), grid);
    }
```