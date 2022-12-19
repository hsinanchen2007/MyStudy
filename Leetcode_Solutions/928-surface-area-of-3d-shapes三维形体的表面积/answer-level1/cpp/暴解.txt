### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), area = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int hi = grid[i][j];
                if(hi>0)
                {
                    area += hi*4+2;
                    area -= i>0?min(hi, grid[i-1][j])*2:0;
                    area -= j>0?min(hi, grid[i][j-1]) *2:0;
                }
            }
        }
        return area;
    }
};
```