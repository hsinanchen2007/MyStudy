### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int h=grid.size();
        int l=grid[0].size();
        int count(0),counti(0),countj(0);
        for(int i=h-1;i>=counti;i--)
        {
            if(grid[i][l-1]>=0)
                break;
            else
            {
                for(int j=l-1;j>=countj;j--)
                {
                    if(grid[i][j]<0)
                    {
                        count++;
                    }
                    else
                    {
                        countj=j-1;
                        break;
                    }
                }
            }
        }
        return count;
    }
};
```