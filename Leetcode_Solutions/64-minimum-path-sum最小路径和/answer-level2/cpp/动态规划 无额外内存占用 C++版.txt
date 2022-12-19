![image.png](https://pic.leetcode-cn.com/b03ffa1309c1807babf82285392b0d055529083046647ecd9293fa2af5829e74-image.png)

思路还是比较简单的，只更新输入矩阵的第一行
```
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0) continue;
                else if(i==0 && j!=0) grid[i][j] = grid[i][j-1] + grid[i][j];
                else if(i!=0 && j==0) grid[0][j] = grid[0][j] + grid[i][j];
                else grid[0][j] = min(grid[0][j], grid[0][j-1]) + grid[i][j];
            }
        }
        return grid[0][grid[0].size()-1];
    }
};
```