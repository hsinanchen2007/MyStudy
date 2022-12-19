### 解题思路

### 代码

```cpp
class Solution {
public:
    void dfs(int & area, int & maxarea, pair<int, int> index, vector<vector<int>>& grid) {
        int& i = index.first;
        int& j = index.second;
        if (i==-1 || i>=grid.size() || j==-1 || j==grid[0].size()) return;
        if (grid[i][j]==0) return;
        area++;
        maxarea = max(area, maxarea);
        grid[i][j] = 0;
        dfs(area, maxarea, pair<int,int>(i-1,j), grid);
        dfs(area, maxarea, pair<int,int>(i+1,j), grid);
        dfs(area, maxarea, pair<int,int>(i,j-1), grid);
        dfs(area, maxarea, pair<int,int>(i,j+1), grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int maxarea = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {    
                if (grid[i][j]==1) {
                    int area = 0;
                    dfs(area, maxarea, pair<int,int>(i,j), grid);
                }
            }
        }
        return maxarea;
    }
};
```