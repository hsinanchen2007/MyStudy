### 解题思路
遍历grid，计算每个位置处的立方体为整个立体图形所贡献的表面积，进行累加。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int dir[2][4] = {{1,0,-1,0}, {0,1,0,-1}};
        int ans = 0;

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j]){ // if (i,j) 位置有cube，则一定贡献上下两面。侧表面由(i,j)cube的高度与(i+-1,j+-1)cube的高度进行比较决定。
                    ans += 2 + 4 * grid[i][j];
                    for(int k = 0; k < 4; ++k){
                        int x = i + dir[0][k];
                        int y = j + dir[1][k];
                        if(x < 0 || y < 0 || x >= row || y >= col) // 检查是否越界。
                            continue;
                        if(grid[i][j] > grid[x][y]) // if (i,j)cube 比 (x,y)cube 高，即有grid[x][y]个面被遮挡。
                            ans -= grid[x][y];
                        else{ // if (i,j)cube 与 (x,y)cube 一样高或者更矮，则有grid[i][j]个面被遮挡。
                            ans -= grid[i][j];
                        }
                    }
                }
            }
        }

        return ans;
    }
};
```