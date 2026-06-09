### 解题思路
 直接暴力，每个找过去，如果是1的进去四个方向一直找下去，直到没有1出现位置。把找过的地方变成0就行。

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxn = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j]){
                    maxn = max(maxn , dfs(grid , i , j));
                }
            }
        }
        return maxn;
    }

    int dfs(vector<vector<int>>& grid , int x , int y){
        int s = 1;
        grid[x][y] = 0;
        int d[4][2] = {1,0,-1,0,0,1,0,-1};
        for(int i = 0 ; i < 4 ; i++){
            int xx = x + d[i][0];
            int yy = y + d[i][1];
            if(xx < 0 || xx >= grid.size() || yy < 0 || yy >= grid[0].size() || grid[xx][yy] == 0)continue;
            s += dfs(grid , xx , yy);
        }
        return s;
    }
};
```