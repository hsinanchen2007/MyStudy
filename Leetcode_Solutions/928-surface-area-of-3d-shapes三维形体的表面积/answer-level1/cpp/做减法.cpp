### 解题思路
先计算每个位置柱状体的表面积，再减去重叠的部分

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
            int  dx[4]={0,1,-1,0};
            int  dy[4]={1,0,0,-1};
            int m=grid.size();
            int res=0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]>0){
                    res+=6*(grid[i][j])-2*(grid[i][j]-1);
                    for(int k=0;k<4;k++)
                    {
                        int x=i+dx[k];
                        int y=j+dy[k];
                        
                        if(x>=0&&x<m&&y>=0&&y<m)
                        {
                            int pv=min(grid[i][j],grid[x][y]);
                            res-=pv;  //减的时候还是以当前柱体为单位，只减它重叠的部分。与它相邻的不减
                        }
                    }
                    }
                }
            }
            return res;
    }
};
```