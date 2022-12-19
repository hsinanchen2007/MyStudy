### 解题思路
针对多面体表面积，直接求出每一个位置的表面积，每个位置的表面积包括方块的四个方向和上下两个底面，对四个方向进行求解的时候有以下情况：
1、没有方块、面积就是方块数
2、有方块，但是比当前位置少，面积是两者的差值
3、有方块，并且比当前位置方块多，面积为0
需要注意的是，在判断四个方向的时候有可能出界，这时候相当于情况1.
最后在加上上下两个面。

### 代码

```cpp
class Solution {
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<4;k++)
                {
                    int fx=i+dx[k];
                    int fy=j+dy[k];
                    if(fx<0||fx>=n||fy<0||fy>=n)
                    {
                        res+=grid[i][j];
                    }
                    else
                    {
                        if(grid[fx][fy]>=grid[i][j])
                            continue;
                        res+=(grid[i][j]-grid[fx][fy]);
                    }
                }
                if(grid[i][j]>0)
                    res+=2;
            }
        }
        return res;
    }
};
```