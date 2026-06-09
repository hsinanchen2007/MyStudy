### 解题思路
如果放置了大于0个物体，底面和顶面一定会被算上
之后就算前后左右四个面即可
先算前面，判断前面有没有方块，没有的话此处有几个物体，前面就贡献几个面积，前面要是有物体则判断和前面的物体哪个更高，前面的物体更高的话就只能贡献0面积，此处物体高的话则贡献高度差个面积
后面，左面，右面一样

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int xlen = grid.size();
        int res = 0;
        for(int i=0 ; i<xlen ; ++i)
        {
            int ylen = grid[i].size();
            int h;
            for(int j=0;j<ylen;++j)
            {
                if(grid[i][j]>0)    res+=2;
                if(i-1<0)
                {
                    res+=grid[i][j];
                }
                else
                {
                    h = grid[i-1][j];
                    res += h>grid[i][j] ? 0 : grid[i][j]-h;
                }
                if(i+1>=xlen)
                {
                    res+=grid[i][j];
                }
                else
                {
                    h = grid[i+1][j];
                    res += h>grid[i][j] ? 0 : grid[i][j]-h;
                }
                //
                if(j-1<0)
                {
                    res+=grid[i][j];
                }
                else
                {
                    h = grid[i][j-1];
                    res += h>grid[i][j] ? 0 : grid[i][j]-h;
                }
                if(j+1>=ylen)
                {
                    res+=grid[i][j];
                }
                else
                {
                    h = grid[i][j+1];
                    res += h>grid[i][j] ? 0 : grid[i][j]-h;
                }
            }
        }
        return res;
    }
};
```