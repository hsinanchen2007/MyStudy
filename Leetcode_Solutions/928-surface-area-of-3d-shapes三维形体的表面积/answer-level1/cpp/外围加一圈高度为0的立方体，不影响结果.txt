### 解题思路
外围加一圈高度为0的立方体，这样求z方向上重叠的面时讨论变的简单，注意高度方向上重叠的面要满足该处立方体个数>1时才有

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 0 && col == 0) return 0;
        //新建一个网格数组，在原数组外加一圈高度为0的立方体
        int** newgrid = new int*[row+2];
        for(int i = 0; i < row+2; i++){
            newgrid[i] = new int[col+2];
            memset(newgrid[i], 0, (row+2)*sizeof(int));
        }
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                newgrid[i][j] = grid[i-1][j-1];
            }
        }
        int neighbourSurf = 0;
        int heightSurf = 0;
        int sumCube = 0;
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                sumCube += newgrid[i][j];
                heightSurf += (newgrid[i][j] - 1 >= 0) ? (newgrid[i][j] - 1) * 2 : 0;
                neighbourSurf += min(newgrid[i][j], newgrid[i][j-1]);
                neighbourSurf += min(newgrid[i][j], newgrid[i][j+1]);
                neighbourSurf += min(newgrid[i][j], newgrid[i-1][j]);
                neighbourSurf += min(newgrid[i][j], newgrid[i+1][j]);
            }
        }
        //cout << sumCube << neighbourSurf << heightSurf << endl;
        int res = sumCube*6 - neighbourSurf - heightSurf;
        return res;
    }
};
```