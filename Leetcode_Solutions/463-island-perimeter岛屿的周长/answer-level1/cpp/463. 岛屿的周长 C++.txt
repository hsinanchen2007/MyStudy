### 解题思路
1.根据观察可以发现，每多连接一个陆地边长就加2。因此我们可以先统计有多少个陆地，利用推导公式2 * n + 2来计算岛屿的周长。
2.当3个陆地集中乘一个大正方形陆地则其周长长度与3个陆地的周长相等。

### 代码

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
            int count = 0;
    for(int i = 0;i<grid.size();++i){
        for(int j =0;j<grid[0].size();++j){
            if(grid[i][j] == 1) ++count;
        }
    }
    for(int i = 0;i<grid.size()-1;++i){
        for( int j =0;j<grid[0].size()-1;++j){
            if(grid[i][j] == 1 && grid[i][j+1] == 1 &&grid[i+1][j] == 1 && grid[i+1][j+1] == 1){
                count--;
            }
        }
    }
    return 2 * count + 2;
    }
};
```