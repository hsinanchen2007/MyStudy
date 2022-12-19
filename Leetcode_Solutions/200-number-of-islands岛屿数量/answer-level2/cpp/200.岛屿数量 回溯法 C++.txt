### 解题思路
用mm来标记是否遍历过
对每个点，若其为1，且未被遍历过，把与其为同一个岛屿的点mm都置为true
![image.png](https://pic.leetcode-cn.com/a3b7f138e23af420913e0885e02190f664950c5c2fc92d4648086f7ddd86dedc-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> step = {{0,1},{0,-1},{1,0},{-1,0}};
    void find_island(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& mm) {
        int m = grid.size();
        int n = grid[0].size();
        if (x >= m || y >= n || x < 0 || y < 0) return;
        if (grid[x][y] == '0') return;
        if (mm[x][y]) return;
        mm[x][y] = true;
        
        for (int i = 0; i < 4; i++) {
            find_island(x + step[i][0], y + step[i][1], grid, mm);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<bool>> mm;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            vector<bool> tmp(n, false);
            mm.push_back(tmp);
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && mm[i][j] == false) {
                    find_island(i, j, grid, mm);
                    res++;
                }
            }
        }
        return res;
    }
};
```