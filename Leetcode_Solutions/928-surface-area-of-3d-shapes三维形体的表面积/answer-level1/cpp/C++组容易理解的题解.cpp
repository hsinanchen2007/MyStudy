### 解题思路

内存消耗 :
9 MB
, 在所有 C++ 提交中击败了
94.44%
的用户
在(i,j)坐标上有一个方块增加6个表面积，每多一个方块增加4个表面积，再看相邻的位置方块，分别对（i+1,j）和（i，j+1)进行处理。注意边界。
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
      int ans = 0;
      if(grid.size()==0) return ans;
      for(int i = 0;i<grid.size();i++){
          if(grid[i].size()==0)continue;
          else{
          for(int j= 0;j<grid[i].size();j++){
              if(grid[i][j]>0){
                  ans += (grid[i][j]-1)*4+6;
                  ans -= subtract(i,j,grid);
              }
           }
          }
      }
      return ans;
    }
    int subtract (int i, int j,vector<vector<int>>& grid){
              int count = 0;
              if(i<grid.size()-1){
                  count += min(grid[i][j],grid[i+1][j])*2;
              }
              if(j<grid[i].size()-1){
                count += min(grid[i][j],grid[i][j+1])*2;
              }
              return count;
    }
};
```
```
### 代码

```cpp
