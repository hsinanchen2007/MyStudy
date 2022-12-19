`class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int F[m][n]={0};
        F[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-2;i>=0;i--){
            F[i][n-1]=F[i+1][n-1]+grid[i][n-1];
        }
        for(int j=n-2;j>=0;j--){
            F[m-1][j]=F[m-1][j+1]+grid[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                F[i][j]=min(F[i][j+1],F[i+1][j])+grid[i][j];
            }
        }
        return F[0][0];
    }
};

我的思路，仅供参考`