### 解题思路
直接找移动之后每个点横纵坐标位置

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int k1=grid.size(),k2=grid[0].size();
        vector<vector<int>>v(k1,vector<int>(k2));
        for(int i=0;i<k1;++i)
        {
            for(int j=0;j<k2;++j)
            {
                int col=(k+j)%k2;
                int row=(i+(k+j)/k2)%k1;
                v[row][col]=grid[i][j];
            }
        }
        return v;
    }
};
```