### 解题思路
首先不考虑面积相邻立方体，最后使用向左和向上逐个区域减去相邻面积。

### 代码

```cpp
class Solution {
public:
int dir[2][2]={{-1,0},{0,-1}};
int surfaceArea(vector<vector<int> >& grid)
{
    int len=grid.size();
    int mark[len+1][len+1];
    memset(mark,0,sizeof(mark));

    int ans=0;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(grid[i][j])
            {
                ans+=grid[i][j]*4+2;
                for(int k=0;k<2;k++)
                {
                    int x_=i+dir[k][0];
                    int y_=j+dir[k][1];
                    if(x_>=0&&x_<len&&y_>=0&&y_<len)
                    {
                        int middle=min(grid[i][j],grid[x_][y_]);
                        ans-=middle*2;
                    }

                }
            }
        }
    }

    return ans;
}
};
```