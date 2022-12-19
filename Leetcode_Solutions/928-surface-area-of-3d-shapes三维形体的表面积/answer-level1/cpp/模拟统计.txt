### 解题思路
参考官方题解:
统计每个立方体贡献的表面积
1.grid[i][j]<=0:不会贡献任何表面积
1.只要grid[i][j]>0,那么其上下面就会贡献两个单位面积
2.grid[i][j]>0时,和周围上下左右的四个立方体比较高度,当前立方体只会贡献比周围立方体高出的那部分面积

### 代码

```cpp
class Solution {
public:
    int dir_x[4]={0,0,1,-1};
    int dir_y[4]={1,-1,0,0};
    int surfaceArea(vector<vector<int>>& grid) {
        int rows=grid.size();if(rows<=0) return 0;
        int cols=grid[0].size();if(cols<=0) return 0;
        int result=0;
        for(int i=0;i<rows;i++)   //单独统计每个立方体贡献的表面积
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]<=0) continue;
                result+=2;   //上下面
                for(int d=0;d<4;d++)
                {
                    int x=i+dir_x[d];
                    int y=j+dir_y[d];
                    if(x<0 || x>=rows || y<0 || y>=cols)
                       result+=grid[i][j];         //最边上
                    else
                       result+=max(grid[i][j]-grid[x][y],0);  //相比周围立方体高出的那一截
                }
            }
        return result;
    }
};
```