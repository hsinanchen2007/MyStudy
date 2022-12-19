与二维动态规划没什么差别，只是在原数组做修改而已，所以还是很快的。
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size();i++){
            grid[i][0]=grid[i-1][0]+grid[i][0];//初始化第一行
        }
        for(int j=1;j<grid[0].size();j++){
            grid[0][j]=grid[0][j-1]+grid[0][j];//初始化第一列
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]=min(grid[i][j-1],grid[i-1][j])+grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
```
