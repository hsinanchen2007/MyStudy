### 解题思路
一个位置一个位置地进行立体柱表面积累加，当一个位置上有n个小正方体累在一起时，表面积为4n+2(2为上下底面,4n为周围四个面)，当沿横向或纵向紧挨继续添加立方体柱时，就会有重叠部分，重叠部分面积为较矮立体柱的个数乘以2（每两个立体柱减少的面积）。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]!=0)
                    res+=4*grid[i][j]+2;
                if(i!=0)
                    res-=min(grid[i-1][j],grid[i][j])*2;
                if(j!=0)
                    res-=min(grid[i][j-1],grid[i][j])*2;
            }
        return res;
    }
};
```