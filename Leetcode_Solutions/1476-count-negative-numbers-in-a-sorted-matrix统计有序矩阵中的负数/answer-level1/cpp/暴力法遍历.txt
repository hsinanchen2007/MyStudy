### 解题思路
循环

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int len1 = grid.size(),len2=grid[0].size();
        int result =0;
        if (len1==0||len2==0)
        {
            return 0;

        }
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(grid[i][j]<0)
                {
                    result++;
                }
            }
        }
        return result;
    }
};
```