### 解题思路
grid[i][j]表示当前点的最短路径和
两层循环：在循环体中判断，如果是上边界，则直接加上左边的值；
如果是左边界，则直接加上上边值
如果是一般情况，比较左边和上边的值，加上两者之间的较小值。

### 代码
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j!=0)grid[i][j]+=grid[i][j-1];
                if(i!=0&&j==0)grid[i][j]+=grid[i-1][j];
                if(i!=0&&j!=0)grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};