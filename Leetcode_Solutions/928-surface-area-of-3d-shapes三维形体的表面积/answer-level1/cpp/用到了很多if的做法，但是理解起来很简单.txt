### 解题思路
举例子
[[2]]    为(0,0)->2
[[1,2],[3,4]]    为 (0,0)->1 | (0,1)->2 | (1,0)->3 | (1,1)->4
[[5,3,7][1,2,8]]   为(0,0)->5 | (0,1)->3 | (0,2)->7 | (1,0)->1 | (1,1)->2 | (1,2)->8
解题思路
1.添加三维体的上下面积
2.添加三维体的四周面积
3.添加三维体中间因叠加数量不同多出的面积。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
         int S=0;
         int n=grid.size();
         for(int i=0;i<n;i++)
         {
             int m=grid[i].size();
             for(int j=0;j<m;j++)
             {
                //添加三维体的上下面积
                S+=grid[i][j]>0?2:0;
                //以下四个if添加三维体的四周面积
                if(i==0)
                    S+=grid[i][j];
                if(i==n-1)
                    S+=grid[i][j];
                if(j==0)
                    S+=grid[i][j];
                if(j==n-1)
                    S+=grid[i][j];
                //以下两个if添加三维体的中间参差不齐的面积
                if(i!=n-1)
                    S+=grid[i][j]>grid[i+1][j]?grid[i][j]-grid[i+1][j]:grid[i+1][j]-grid[i][j];  
                if(j!=n-1)
                    S+=grid[i][j]>grid[i][j+1]?grid[i][j]-grid[i][j+1]:grid[i][j+1]-grid[i][j];
             }
         }
         return S;

    }
};
```