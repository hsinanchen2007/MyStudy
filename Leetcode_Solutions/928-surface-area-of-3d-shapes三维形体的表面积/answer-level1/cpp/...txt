### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        
        int dx[] = { 0,  0, -1,  1};
        int dy[] = {-1,  1,  0,  0};

        for(int i = 0, n = grid.size(); i < n; ++i) {
            for(int k = 0, m = grid[i].size(); k < m; ++k) {
                if(grid[i][k] <= 0 ) {
                    continue;
                }
                sum += grid[i][k]*4 + 2;
                for(int j = 0; j < 4; j++) {
                    int tx = i + dx[j], ty = k+dy[j];
                    if(0 <= tx && tx < n && 0 <= ty && ty < m) {
                        sum -= min(grid[i][k], grid[tx][ty]);
                    }
                }
            }
        }
        return sum;
    }
};


```