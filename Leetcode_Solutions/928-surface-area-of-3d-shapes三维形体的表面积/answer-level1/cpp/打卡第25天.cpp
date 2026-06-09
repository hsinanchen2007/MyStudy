先独立计算每一个柱体的表面积，然后逐行逐列地减去上方和左方的重合面积，重合的面积是2倍的相邻最小值
```
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                sum +=  (grid[i][j]<<2)+2;
                }
                if(i>0){
                    sum -= 2 * min(grid[i-1][j],grid[i][j]);
                }
                if(j>0){
                    sum -= 2 * min(grid[i][j-1], grid[i][j]);
                }

            }
        }
        return sum;
       


    }
};
```
