遍历所有的网格，如果是陆地，则判断上下左右，四个边界和水域相连接，则分别加1；



class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid.at(0).size();
        int len = 0;
        for(int row=0; row< rows; row ++)
        {
            for(int col =0; col< cols; col++)
            {
                if( grid[row][col] )
                {
                    if(row == 0)    // 上边缘
                        len ++;
                    else
                        len += !grid[row-1][col];

                    if(row == rows-1) // 下边缘
                        len ++;
                    else
                        len += !grid[row+1][col];

                    if(col == 0)       // 左边缘
                        len ++;
                    else
                        len += !grid[row][col-1];
                    if(col == cols-1)   // 右边缘
                        len ++;
                    else
                        len += !grid[row][col+1];
                }
            }
        }
        return len;
    }
};