class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int i = 0, j = n-1;
        if(grid[0][0] <0) return m*n; // 如果第一个数据为负，则所有的数据为负数。

        while(i < m && j >= 0) {
            if(grid[i][j] < 0) {
               while(j >= 0 && grid[i][j] < 0) j--;
            }
            res += n-j-1;
            i ++;
        }
        if (j == -1 && i < m) res += n*(m-i);
        return res;
    }
};