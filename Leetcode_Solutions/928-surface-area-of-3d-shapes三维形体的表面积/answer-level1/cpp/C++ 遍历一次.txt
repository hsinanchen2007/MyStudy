### 解题思路
逐行扫描，扫描一遍，时间复杂度O(N*2),空间复杂度O(1).
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int count=0,over=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid.size();++j){
                if(grid[i][j]){
                    over+=2*(grid[i][j]-1);
                    if(j+1!=grid.size())
                        over+=2*min(grid[i][j],grid[i][j+1]);
                    if(i+1!=grid.size())
                        over+=2*min(grid[i][j],grid[i+1][j]);
                }
            count+=grid[i][j];
            }
        }
        return 6*count-over;
    }
};
```