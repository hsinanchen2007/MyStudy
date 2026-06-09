### 解题思路
想到的思路已就是查找每个为1的点上下左右点是否还是1,是的话继续，不是则不满足了。

### 代码

```cpp
class Solution {
public:
    void getNeighbors(vector<vector<int>>& grid, int x, int y, int& count, int(&offset)[4][2])
    {
        int row = grid.size();
        int coloum = grid[0].size();
        if(grid[x][y] == 0) return;
        grid[x][y] = 0;
        count = count + 1;
        for(int i = 0; i < 4; i++)
        {
            int offsetX = offset[i][0];
            int offsetY = offset[i][1];
            if(x + offsetX < 0
            || x + offsetX >= row
            || y + offsetY < 0
            || y + offsetY >= coloum)
            {
                continue;
            }
            if(grid[x + offsetX][y + offsetY] == 1)
            {
                getNeighbors(grid, x + offsetX, y + offsetY, count, offset);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int offset[4][2] ={
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        int area = 0;
        int max = area;
        auto cloneGrid = grid;
        for(int x = 0; x < cloneGrid.size(); x++)
        {
            for(int y = 0; y < cloneGrid[x].size(); y++)
            {
                getNeighbors(cloneGrid, x, y, area, offset);
                if(area > max)
                {
                    max = area;
                }
                area = 0;
            }
        }

        return max;
    }
};
```