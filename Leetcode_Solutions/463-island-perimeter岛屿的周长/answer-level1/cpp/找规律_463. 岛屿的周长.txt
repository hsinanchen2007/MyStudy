### 解题思路
    /*
     * 找规律
     *
     * 因为被水包围的恰好只有一个岛屿，且岛屿中没有湖，
     * 而岛屿由矩形组成，所以它的边是对称的。
     * 所以计算岛屿的边长，只需要计算一半即可，
     * 上边和左边的长和或者下边和右边的长和。
     *
     * 对网格的点进行遍历，当该点的值为1时，
     * 判断该点是否在第一行或左边的点值为0，如果是就边长加1；
     * 判断该点是否在第一列或上边的点值为0，如果是就边长加1。
     * 最后返回计算的边和的2倍。
     * */
### 代码

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // 一半边长和
    int perimeter = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            // 如果该点的值为1
            if(grid[i][j] == 1){
                // 该点是否在第一行或左边的点值为0
                if(i == 0 || grid[i-1][j] == 0){
                    // 边长加1
                    perimeter++;
                }

                // 该点是否在第一列或上边的点值为0
                if(j==0 || grid[i][j-1]==0){
                    // 边长加1
                    perimeter++;
                }
            }
        }
    }

    // 返回边长和的两倍
    return perimeter*2;
    }
};
```