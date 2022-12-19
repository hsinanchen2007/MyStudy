最简单最快的动态规划，在原数组上修改，也就是原数组就是DP数组。

数组的每一个位置的值，表示到达当前位置中走的数字最小的值。

如果是边界，特殊处理。

如果不是边界，那么就是当前位置的值，加上上边或者左边小的值。

``` c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //实现原数组修改
        int coll, rowl;
        coll = grid.size();
        if(coll == 0) return 0;
        rowl = grid[0].size();
        for(int col = 0; col < coll;col++){
            for(int row = 0; row < rowl; row++){
                if(col == 0 && row == 0) continue;
                else if(col == 0 && row != 0) grid[col][row] += grid[col][row-1];
                else if(col != 0 && row == 0) grid[col][row] += grid[col-1][row];
                else{
                    grid[col][row] += min(grid[col][row-1],grid[col-1][row]);
                }
            }
        }
        return grid[coll-1][rowl-1];
    }
};
```
