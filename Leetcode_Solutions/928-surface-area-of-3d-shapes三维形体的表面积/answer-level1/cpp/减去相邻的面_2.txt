### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum += grid[i][j]*6;
                sum -= std::max(grid[i][j]-1, 0)*2;
                if(j > 0) sum -= std::min(grid[i][j-1], grid[i][j])*2;
                if(i > 0){
                    sum -= std::min(grid[i-1][j], grid[i][j])*2;
                }
            }
            
        }
        return sum;
    }
};
```