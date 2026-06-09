### 解题思路
此处撰写解题思路
其实第一看到题，我想到了最短路径的求解，但是这个路径方向有限制，故第一行，第一列的值是确定的，其他位置的值，都能基于此迭代出来。但是解法过程，创建的求和数组有点多余，可以直接用原来的路径数组当做求和数组处理，性能应该能更提升。

### 代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        int sum_grid[m][n] = {0};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(0==i){
                    if(0==j){
                        sum_grid[i][j] = grid[0][0];
                    }
                    else{
                        sum_grid[i][j] = sum_grid[i][j-1]+grid[0][j];
                    }
                }
                else{
                    if(0==j){
                        sum_grid[i][j] = sum_grid[i-1][0] + grid[i][0];
                    }
                    else{
                        sum_grid[i][j] = (sum_grid[i-1][j]<sum_grid[i][j-1]?sum_grid[i-1][j]:sum_grid[i][j-1])+grid[i][j];
                    }
                }
            }
        }
        return sum_grid[m-1][n-1];
    }
    
};
```