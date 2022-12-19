### 解题思路
这题思路如下：
   最终表面积 = 所有立方体表面积之和-各个立方体相互接触次数*2

就上面一句话即可。没啥很绕的逻辑！代码如下：

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {

        //最终表面积 = 所有立方体表面积之和-各个立方体相互接触次数*2
        int ccount = 0;
        int totalv = 0;
        if(grid.size() == 0){
            return 0;
        }
        int lenx = grid[0].size();
        int leny = grid.size();

        int i = 0;
        int j = 0;
        for(i = 0;i<leny;i++){
            for(j = 0;j<lenx-1;j++){

                if(i == 0){
                  ccount += min(grid[i][j+1] , grid[i][j]);
                  if(grid[i][j]>0)
                    ccount += (grid[i][j] - 1);
                  }
                else{
                    ccount += min(grid[i][j+1],grid[i][j]);
                    ccount += min(grid[i][j],grid[i-1][j]);
                    if(grid[i][j]>0)
                        ccount += (grid[i][j] - 1);
                }

                totalv += grid[i][j]; 
            }
            totalv += grid[i][j]; 
            if(i != 0){
                ccount += min(grid[i][j],grid[i-1][j]);
                }
            if(grid[i][j]>0)
                ccount += (grid[i][j] - 1);
        }

        return totalv*6 - ccount*2;
    }
};
```