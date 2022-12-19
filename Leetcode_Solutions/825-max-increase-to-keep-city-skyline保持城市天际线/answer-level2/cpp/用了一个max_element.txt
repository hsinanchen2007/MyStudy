### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
     int ret=0;
     vector<int> colmax;//保存列最大值
     for (int j=0;j<grid[0].size();j++)
         {
             int max=0;
          for (int i=0;i<grid.size();i++)
         {
             if (grid[i][j]>max)
             max=grid[i][j];
         }
         colmax.push_back(max);
     }

 for (int i=0;i<grid.size();i++)
     {
       for (int j=0;j<grid[0].size();j++)
           {
               int m =*max_element(grid[i].begin(),grid[i].end());//利用max_element找到行最大
               ret+=min(colmax[j],m)-grid[i][j];//结果即为行列最大值中较小的与本数之差
           }
      }
        return ret;
    }
};
```