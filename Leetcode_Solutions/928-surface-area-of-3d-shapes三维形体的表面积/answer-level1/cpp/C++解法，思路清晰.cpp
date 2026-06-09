### 解题思路
整体思路都在代码的注释中了，很容易懂

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row=grid.size();//获取大小N
        int vol=0;//初始化体积

        //遍历整个二维数组，暂时不考虑左右相隔，
        //计算出二维网格中的每个网格的表面积
        //计算公式就是4*正方体个数+2（4为正方体前后左右，2为上下表面）
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<row;++j)
            {
                if(grid[i][j]!=0)
                {   
                    vol+=4*grid[i][j]+2;
                }
            }
        }
        //再次遍历二维网格，仅考虑右边和下边有没有正方体即可，原因是
        //从左上开始遍历的，每次仅考虑右下有没有正方体就可以知道有没有正方体的面被遮挡
        //注意不要右边和下边越界即可
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<row;++j)
            {
                if(grid[i][j]!=0)
                {
                    if((j+1)<row&&(grid[i][j+1]!=0))
                    {
                        //两个正方体相遇，被遮挡的面积取决于最少的正方体数
                        int sub_row=min(grid[i][j],grid[i][j+1]);
                        //当右边遇到一个正方体，这时候总面积将会减少两个面
                        vol -= 2*sub_row;
                    }
                    if((i+1)<row&&(grid[i+1][j]!=0))
                    {
                        int sub_col=min(grid[i][j],grid[i+1][j]);
                        vol -= 2*sub_col;
                    }
                }
            }
        }
        return vol;

    }
};
```