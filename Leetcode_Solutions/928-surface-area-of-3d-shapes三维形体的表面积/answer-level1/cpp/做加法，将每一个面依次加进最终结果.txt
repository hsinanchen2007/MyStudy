### 解题思路
以每一个位置的方体为单位，判断它的每一个面是否能够加进去

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int dx[4]={1,0,0,-1};
        int dy[4]={0,1,-1,0};
        int  res=0;
        int m=grid.size();
        int n=grid[0].size();
     
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(grid[i][j]>0)
               {
                   res+=2;//顶面和底面
                   for(int k=0;k<4;k++)
                   {
                       int x=i+dx[k];
                       int y=j+dy[k];
                       int p=0;  //如果遇到了上下左右不存在的情况，那么这一面就没有被遮住的，直////接//加上
                       if(x>=0&&x<m&&y>=0&&y<n)
                       p=grid[x][y];



                       res+=max(grid[i][j]-p,0);
                   }
               }

                }
            
            }
            return res;
        
    }
};
```