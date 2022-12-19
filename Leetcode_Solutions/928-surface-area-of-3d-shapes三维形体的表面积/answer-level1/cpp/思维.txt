### 解题思路
思维

### 代码

```cpp
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int r = grid.size();
        if(r==0) return 0;
        int solve = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<r;j++)
            {
                //判断每一个方块的5个面是否能漏出来
                if(grid[i][j]==0) continue;
                solve+=2;
                for(int k=0;k<4;k++)
                {
                    int nx = i + dx[k] , ny = j + dy[k];
                    if(nx>=0&&nx<r&&ny>=0&&ny<r) {
                        if(grid[i][j]>grid[nx][ny]) {
                            solve += grid[i][j] - grid[nx][ny];
                        }
                    }
                    else {
                        solve+=grid[i][j];
                    }
                }
            }
        }
        return solve;
    }
};
```