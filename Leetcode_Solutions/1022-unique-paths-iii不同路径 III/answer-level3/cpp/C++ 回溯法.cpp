```
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    void backtrace(vector<vector<int> >& grid, int r, int c, int R, int C, 
            vector<vector<bool> >& visited, int n, int N,
            vector<pair<int, int> >& solution,
            set<vector<pair<int, int> > >& res) {
        if (!valid(r, c, R, C) || grid[r][c] == -1 || visited[r][c])
            return;
        if (grid[r][c] == 2 && n == N) {
            res.insert(solution);
            return;
        }
        visited[r][c] = true;
        solution.push_back({r, c});
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            backtrace(grid, nr, nc, R, C, visited, n + 1, N, solution, res);
        }
        visited[r][c] = false;
        solution.pop_back();
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int R = grid.size();
        int C = grid[0].size();
        int N = 1;
        int r, c;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) { 
                N += grid[i][j] == 0;
                if (grid[i][j] == 1) {
                    r = i;
                    c = j;
                }
            }
        }
        vector<vector<bool> > visited(R, vector<bool>(C, false));
        vector<pair<int, int> > solution;
        set<vector<pair<int, int> > > res;
        backtrace(grid, r, c, R, C, visited, 0, N, solution, res);
        return res.size();
    }
};
```

