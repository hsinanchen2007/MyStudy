class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int >>ans(m,vector<int>(n));
        //第i行j列的元素，进k列，也就会进((k+j)/n)行

        for(int i =0;i<grid.size();i++){
                for(int j=0;j<n;j++){
                    int hang =((k+j)/n+i)%m;
                     int lie  =(k+j)%n;
                     ans[hang][lie]=grid[i][j];
                }

        }
        
        return ans;
    }
};