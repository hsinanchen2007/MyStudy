### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int overlap=0,z=0,zero=0;
       for(int i=0;i<grid.size();i++){
        for(int j=1;j<grid.size();j++){
            overlap+=min(grid[i][j],grid[i][j-1])+min(grid[j][i],grid[j-1][i]);
            z+=grid[i][j];
            if(!grid[i][j])zero++;
        }
            z+=grid[i][0];
            if(!grid[i][0])zero++;
       }
            return 6*z-(z-(grid.size()*grid.size()-zero))*2-overlap*2;
    }
};
```