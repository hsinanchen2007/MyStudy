### 解题思路
新建一个visited数组，用于记录每个点是否被访问过
void bfs(int i, int j, vector<vector<int>> grid, int &area, int width, int height,vector<vector<int>> &visited)
改成
void bfs(int i, int j, const vector<vector<int>> &grid, int &area, const int &width, const int &height,vector<vector<int>> &visited)
之后
执行用时2552ms->16ms, 内存消耗622MB->11MB
影响很明显
前面的有大量的构造函数和拷贝构造函数的调用，消耗大量的空间和时间
### 代码

```cpp
class Solution {
public:
    void bfs(int i, int j, const vector<vector<int>> &grid, int &area, const int &width, const int &height,vector<vector<int>> &visited) {
        // 四个方向
        // i > 0就有i-1
        // j >0 就有j-1
        // i < height - 1 就有i+1
        // j < width - 1 就有 j+1
        if(grid[i][j] == 1 && visited[i][j] == 0) {
            visited[i][j] = 1;
            area += 1;
            if(i > 0) {
                bfs(i-1, j, grid, area, width, height, visited);
            }
            if(j > 0) {
                bfs(i, j-1, grid, area, width, height, visited);
            }
            if(i < (height - 1)) {
                bfs(i+1, j, grid, area, width, height, visited);
            }
            if(j < (width - 1)) {
                bfs(i, j+1, grid, area, width, height, visited);
            }
        } else {
            return ;
        }
    }
    // 岛屿最大面积
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 应该是dfs方法吧
        int width = grid[0].size();
        int height = grid.size();
        //vector<vector<int>> visited(0, vector<int>(0));
        vector<vector<int>> visited(height, vector<int>(width, 0));

        int max = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                // 对于每一个点访问其相邻的四个方向的点
                // 如果没有访问过
                int area = 0;

                //cout << visited[i][j] << endl;
                if (visited[i][j] == 0 && grid[i][j] == 1) {
                    bfs(i, j, grid, area, width, height, visited);
                }
                if (area > max) {
                    max = area;
                }
            }
        }
        return max;
    }
};
```