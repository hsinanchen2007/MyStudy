### 解题思路
最难的是理解题目。
从上到下，从左到右。
先求[i][j]上立方体的表面积，然后减去左边[i-1][j]和上边[i][j-1]重合的表面积，结束。


### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0;
        //int a[4]={0,-1};
        //int b[4]={-1,0};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    ans+=4*grid[i][j]+2;
                    if(0<i) ans-=2*min(grid[i][j],grid[i-1][j]);
                    if(0<j) ans-=2*min(grid[i][j],grid[i][j-1]);
                }
            }
        }
        return ans;
    }
};
```