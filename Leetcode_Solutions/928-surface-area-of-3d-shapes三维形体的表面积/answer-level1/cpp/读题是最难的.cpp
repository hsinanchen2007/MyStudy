### 解题思路
每个点的堆叠立方体本身的上底和下底面积为2，然后再减去前后左右重叠的面积，注意处于边界点的情况就行

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n=grid.size(),res=0;
        if(n==1) return 2+4*grid[0][0];//1x1网格
        for(int i=0;i<n;i++)
        {//每一行
            for(int j=0;j<n;j++)
            {//每一列
                if(grid[i][j] > 0)
                {//这个点若有立方体
                    res +=  2;//上底和下底面积
                    if(i==0 || i==n-1) res += grid[i][j];//处于前后边界
                    if(j==0 || j==n-1) res += grid[i][j];//处于前后边界
                    if(j-1>=0 && grid[i][j-1]<grid[i][j])//减掉左边重叠的面积
                        res += grid[i][j] - grid[i][j-1];
                    if(j+1<n && grid[i][j+1]<grid[i][j])//减掉右边重叠的面积
                        res += grid[i][j] - grid[i][j+1];
                   if(i+1<n && grid[i+1][j]<grid[i][j])//减掉前面重叠的面积
                        res += grid[i][j] - grid[i+1][j];
                   if(i-1>=0 && grid[i-1][j]<grid[i][j])//减掉后面重叠的面积
                        res += grid[i][j] - grid[i-1][j];
                }
            }
        }
        return res;
    }
};
```